/*
 * Copyright (C) 2005-2011 MaNGOS <http://getmangos.com/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "vmapexport.h"
#include "model.h"
#include "wmo.h"
#include "mpq_libmpq04.h"
#include <cassert>
#include <algorithm>
#include <cstdio>

extern int expansion;

Model::Model(std::string &filename) : filename(filename), vertices(0), indices(0)
{
    memset(&header, 0, sizeof(header));
}

bool Model::open()
{
    MPQFile f(filename.c_str());

    if (f.isEof())
    {
        f.close();
        // Do not show this error on console to avoid confusion, the extractor can continue working even if some models fail to load
        //printf("Error loading model %s\n", filename.c_str());
        return false;
    }

    _unload();

    if(expansion == 0 || expansion == 1)
    {
        ModelHeader0 header0;
        memcpy(&header0, f.getBuffer(), sizeof(ModelHeader0));
        memcpy(&header.id, &header0.id, sizeof(char)*4);
        memcpy(&header.version, &header0.version, sizeof(uint8)*4);
        header.nameLength = header0.nameLength;
        header.nameOfs = header0.nameOfs;
        header.type = header0.type;
        header.nGlobalSequences = header0.nGlobalSequences;
        header.ofsGlobalSequences = header0.ofsGlobalSequences;
        header.nAnimations = header0.nAnimations;
        header.ofsAnimations = header0.ofsAnimations;
        header.nAnimationLookup = header0.nAnimationLookup;
        header.ofsAnimationLookup = header0.ofsAnimationLookup;
        header.nBones = header0.nBones;
        header.ofsBones = header0.ofsBones;
        header.nKeyBoneLookup = header0.nKeyBoneLookup;
        header.ofsKeyBoneLookup = header0.ofsKeyBoneLookup;
        header.nVertices = header0.nVertices;
        header.ofsVertices = header0.ofsVertices;
        header.nViews = header0.nViews;
        header.nColors = header0.nColors;
        header.ofsColors = header0.ofsColors;
        header.nTextures = header0.nTextures;
        header.ofsTextures = header0.ofsTextures;
        header.nTransparency = header0.nTransparency;
        header.ofsTransparency = header0.ofsTransparency;
        header.nUVAnimation = header0.nTextureanimations;
        header.ofsUVAnimation = header0.ofsTextureanimations;
        header.nTexReplace = header0.nTexReplace;
        header.ofsTexReplace = header0.ofsTexReplace;
        header.nRenderFlags = header0.nRenderFlags;
        header.ofsRenderFlags = header0.ofsRenderFlags;
        header.nBoneLookupTable = header0.nBoneLookupTable;
        header.ofsBoneLookupTable = header0.ofsBoneLookupTable;
        header.nTexLookup = header0.nTexLookup;
        header.ofsTexLookup = header0.ofsTexLookup;
        header.nTexUnitLookup = header0.nTexUnits;
        header.ofsTexUnitLookup = header0.ofsTexUnits;
        header.nTransparencyLookup = header0.nTransLookup;
        header.ofsTransparencyLookup = header0.ofsTransLookup;
        header.nUVAnimLookup = header0.nTexAnimLookup;
        header.ofsUVAnimLookup = header0.ofsTexAnimLookup;

        header.vertexbox1[0] = header0.vertexbox1[0];
        header.vertexbox1[1] = header0.vertexbox1[1];
        header.vertexbox1[2] = header0.vertexbox1[2];

        header.vertexbox2[0] = header0.vertexbox2[0];
        header.vertexbox2[1] = header0.vertexbox2[1];
        header.vertexbox2[2] = header0.vertexbox2[2];

        header.vertexradius = header0.vertexradius;

        header.boundingbox1[0] = header0.boundingbox1[0];
        header.boundingbox1[1] = header0.boundingbox1[1];
        header.boundingbox1[2] = header0.boundingbox1[2];

        header.boundingbox2[0] = header0.boundingbox2[0];
        header.boundingbox2[1] = header0.boundingbox2[1];
        header.boundingbox2[2] = header0.boundingbox2[2];

        header.boundingradius = header0.boundingradius;

        header.nBoundingTriangles = header0.nBoundingTriangles;
        header.ofsBoundingTriangles = header0.ofsBoundingTriangles;
        header.nBoundingVertices = header0.nBoundingVertices;
        header.ofsBoundingVertices = header0.ofsBoundingVertices;
        header.nBoundingNormals = header0.nBoundingNormals;
        header.ofsBoundingNormals = header0.ofsBoundingNormals;
        header.nAttachments = header0.nAttachments;
        header.ofsAttachments = header0.ofsAttachments;
        header.nAttachmentLookup = header0.nAttachLookup;
        header.ofsAttachmentLookup = header0.ofsAttachLookup;
        header.nEvents = header0.nAttachments_2;
        header.ofsEvents = header0.ofsAttachments_2;
        header.nLights = header0.nLights;
        header.ofsLights = header0.ofsLights;
        header.nCameras = header0.nCameras;
        header.ofsCameras = header0.ofsCameras;
        header.nCameraLookup = header0.nCameraLookup;
        header.ofsCameraLookup = header0.ofsCameraLookup;
        header.nRibbonEmitters = header0.nRibbonEmitters;
        header.ofsRibbonEmitters = header0.ofsRibbonEmitters;
        header.nParticleEmitters = header0.nParticleEmitters;
        header.ofsParticleEmitters = header0.ofsParticleEmitters;
    }
    else
        memcpy(&header, f.getBuffer(), sizeof(ModelHeader));

    if(header.nBoundingTriangles > 0)
    {
        f.seek(0);
        f.seekRelative(header.ofsBoundingVertices);
        vertices = new Vec3D[header.nBoundingVertices];
        f.read(vertices,header.nBoundingVertices*12);
        for (uint32 i=0; i<header.nBoundingVertices; i++)
            vertices[i] = fixCoordSystem(vertices[i]);
        f.seek(0);
        f.seekRelative(header.ofsBoundingTriangles);
        indices = new uint16[header.nBoundingTriangles];
        f.read(indices,header.nBoundingTriangles*2);
        f.close();
    }
    else
    {
        //printf("not included %s\n", filename.c_str());
        f.close();
        return false;
    }
    return true;
}

bool Model::ConvertToVMAPModel(const char * outfilename)
{
    FILE *output = NULL;
    int N[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
    fopen_s(&output, outfilename, "wb");
    if (!output)
    {
        printf("Can't create the output file '%s'\n",outfilename);
        return false;
    }

    fwrite(szRawVMAPMagic, 8, 1, output);
    uint32 nVertices = header.nBoundingVertices;
    fwrite(&nVertices, sizeof(int), 1, output);
    uint32 nofgroups = 1;
    fwrite(&nofgroups,sizeof(uint32), 1, output);
    fwrite(N,4*3,1,output);// rootwmoid, flags, groupid
    fwrite(N,sizeof(float),3*2,output);//bbox, only needed for WMO currently
    fwrite(N,4,1,output);// liquidflags
    fwrite("GRP ",4,1,output);
    uint32 branches = 1;
    int wsize = sizeof(branches) + sizeof(uint32) * branches;
    fwrite(&wsize, sizeof(int), 1, output);
    fwrite(&branches,sizeof(branches), 1, output);
    uint32 nIndexes = header.nBoundingTriangles;
    fwrite(&nIndexes,sizeof(uint32), 1, output);
    fwrite("INDX",4, 1, output);
    wsize = sizeof(uint32) + sizeof(unsigned short) * nIndexes;
    fwrite(&wsize, sizeof(int), 1, output);
    fwrite(&nIndexes, sizeof(uint32), 1, output);
    if (nIndexes >0)
        fwrite(indices, sizeof(unsigned short), nIndexes, output);

    fwrite("VERT", 4, 1, output);
    wsize = sizeof(int) + sizeof(float) * 3 * nVertices;
    fwrite(&wsize, sizeof(int), 1, output);
    fwrite(&nVertices, sizeof(int), 1, output);
    if (nVertices >0)
    {
        for(uint32 vpos=0; vpos <nVertices; ++vpos)
            std::swap(vertices[vpos].y, vertices[vpos].z);

        fwrite(vertices, sizeof(float)*3, nVertices, output);
    }

    fclose(output);

    return true;
}


Vec3D fixCoordSystem(Vec3D v)
{
    return Vec3D(v.x, v.z, -v.y);
}

Vec3D fixCoordSystem2(Vec3D v)
{
    return Vec3D(v.x, v.z, v.y);
}

ModelInstance::ModelInstance(MPQFile& f, char const* ModelInstName, uint32 mapID, uint32 tileX, uint32 tileY, FILE *pDirfile)
    : model(NULL), AdtId(0), scale(0), flags(0)
{
    f.read(&AdtId, 4);

    float ff[3];
    f.read(ff, 12);
    pos = fixCoords(Vec3D(ff[0], ff[1], ff[2]));
    f.read(ff, 12);
    rot = Vec3D(ff[0], ff[1], ff[2]);

    // scale factor - divide by 1024. blizzard devs must be on crack, why not just use a float?
    f.read(&scale, 2);
    // 0x01 - biom | 0x02 - shrub
    f.read(&flags, 2);

    FILE* input = NULL;
    char tempname[512];
    sprintf_s(tempname, 512, "%s/%s", szWorkDirWmo, ModelInstName);
    fopen_s(&input, tempname, "r+b");
    if (!input)
    {
        //printf("ModelInstance::ModelInstance couldn't open %s\n", tempname);
        return;
    }

    fseek(input, 8, SEEK_SET); // get the correct no of vertices
    int nVertices;
    int count = fread(&nVertices, sizeof (int), 1, input);
    fclose(input);
    if (count != 1 || nVertices == 0)
        return;

    uint32 mod_flags = MOD_M2;
    if (tileX == 65 && tileY == 65)
        mod_flags |= MOD_WORLDSPAWN;

    //write mapID, tileX, tileY, Flags, ID, Pos, Rot, Scale, name
    fwrite(&mapID, sizeof(uint32), 1, pDirfile);
    fwrite(&tileX, sizeof(uint32), 1, pDirfile);
    fwrite(&tileY, sizeof(uint32), 1, pDirfile);
    fwrite(&mod_flags, sizeof(uint32), 1, pDirfile);
    fwrite(&AdtId, sizeof(uint32), 1, pDirfile);
    fwrite(&pos, sizeof(float), 3, pDirfile);
    fwrite(&rot, sizeof(float), 3, pDirfile);
    fwrite(&scale, sizeof(uint16), 1, pDirfile);
    fwrite(&flags, sizeof(uint16), 1, pDirfile);

    uint32 nlen = strlen(ModelInstName);
    fwrite(&nlen, sizeof(uint32), 1, pDirfile);
    fwrite(ModelInstName, sizeof(char), nlen, pDirfile);
}
