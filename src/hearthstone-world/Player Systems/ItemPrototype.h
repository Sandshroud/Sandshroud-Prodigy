/***
 * Demonstrike Core
 */

#pragma once

class Spell;
class GossipScript;

#define GEM_META_SOCKET 1
#define GEM_RED_SOCKET 2
#define GEM_YELLOW_SOCKET 4
#define GEM_BLUE_SOCKET 8

#define MAX_INVENTORY_SLOT 150
#define MAX_BUYBACK_SLOT 13

#define ITEM_NO_SLOT_AVAILABLE -1 //works for all kind of slots now
#define INVENTORY_SLOT_NOT_SET -1

#define EQUIPMENT_SLOT_START         0
#define EQUIPMENT_SLOT_HEAD       0
#define EQUIPMENT_SLOT_NECK       1
#define EQUIPMENT_SLOT_SHOULDERS     2
#define EQUIPMENT_SLOT_BODY       3
#define EQUIPMENT_SLOT_CHEST         4
#define EQUIPMENT_SLOT_WAIST         5
#define EQUIPMENT_SLOT_LEGS       6
#define EQUIPMENT_SLOT_FEET       7
#define EQUIPMENT_SLOT_WRISTS       8
#define EQUIPMENT_SLOT_HANDS         9
#define EQUIPMENT_SLOT_FINGER1     10
#define EQUIPMENT_SLOT_FINGER2     11
#define EQUIPMENT_SLOT_TRINKET1   12
#define EQUIPMENT_SLOT_TRINKET2   13
#define EQUIPMENT_SLOT_BACK       14
#define EQUIPMENT_SLOT_MAINHAND   15
#define EQUIPMENT_SLOT_OFFHAND     16
#define EQUIPMENT_SLOT_RANGED       17
#define EQUIPMENT_SLOT_TABARD       18
#define EQUIPMENT_SLOT_END         19

#define INVENTORY_SLOT_BAG_START     19
#define INVENTORY_SLOT_BAG_1         19
#define INVENTORY_SLOT_BAG_2         20
#define INVENTORY_SLOT_BAG_3         21
#define INVENTORY_SLOT_BAG_4         22
#define INVENTORY_SLOT_BAG_END     23

#define INVENTORY_SLOT_ITEM_START   23
#define INVENTORY_SLOT_ITEM_1       23
#define INVENTORY_SLOT_ITEM_2       24
#define INVENTORY_SLOT_ITEM_3       25
#define INVENTORY_SLOT_ITEM_4       26
#define INVENTORY_SLOT_ITEM_5       27
#define INVENTORY_SLOT_ITEM_6       28
#define INVENTORY_SLOT_ITEM_7       29
#define INVENTORY_SLOT_ITEM_8       30
#define INVENTORY_SLOT_ITEM_9       31
#define INVENTORY_SLOT_ITEM_10     32
#define INVENTORY_SLOT_ITEM_11     33
#define INVENTORY_SLOT_ITEM_12     34
#define INVENTORY_SLOT_ITEM_13     35
#define INVENTORY_SLOT_ITEM_14     36
#define INVENTORY_SLOT_ITEM_15     37
#define INVENTORY_SLOT_ITEM_16     38
#define INVENTORY_SLOT_ITEM_END   39

#define BANK_SLOT_ITEM_START         39
#define BANK_SLOT_ITEM_1             39
#define BANK_SLOT_ITEM_2             40
#define BANK_SLOT_ITEM_3             41
#define BANK_SLOT_ITEM_4             42
#define BANK_SLOT_ITEM_5             43
#define BANK_SLOT_ITEM_6             44
#define BANK_SLOT_ITEM_7             45
#define BANK_SLOT_ITEM_8             46
#define BANK_SLOT_ITEM_9             47
#define BANK_SLOT_ITEM_10           48
#define BANK_SLOT_ITEM_11           49
#define BANK_SLOT_ITEM_12           50
#define BANK_SLOT_ITEM_13           51
#define BANK_SLOT_ITEM_14           52
#define BANK_SLOT_ITEM_15           53
#define BANK_SLOT_ITEM_16           54
#define BANK_SLOT_ITEM_17           55
#define BANK_SLOT_ITEM_18           56
#define BANK_SLOT_ITEM_19           57
#define BANK_SLOT_ITEM_20           58
#define BANK_SLOT_ITEM_21           59
#define BANK_SLOT_ITEM_22           60
#define BANK_SLOT_ITEM_23           61
#define BANK_SLOT_ITEM_24           62
#define BANK_SLOT_ITEM_25           63
#define BANK_SLOT_ITEM_26           64
#define BANK_SLOT_ITEM_27           65
#define BANK_SLOT_ITEM_28           66
#define BANK_SLOT_ITEM_END         67

#define BANK_SLOT_BAG_START       67
#define BANK_SLOT_BAG_1           67
#define BANK_SLOT_BAG_2           68
#define BANK_SLOT_BAG_3           69
#define BANK_SLOT_BAG_4           70
#define BANK_SLOT_BAG_5           71
#define BANK_SLOT_BAG_6           72
#define BANK_SLOT_BAG_7           73
#define BANK_SLOT_BAG_END           74

#define INVENTORY_KEYRING_START   86
#define INVENTORY_KEYRING_1       86
#define INVENTORY_KEYRING_2       87
#define INVENTORY_KEYRING_3       88
#define INVENTORY_KEYRING_4       89
#define INVENTORY_KEYRING_5       90
#define INVENTORY_KEYRING_6       91
#define INVENTORY_KEYRING_7       92
#define INVENTORY_KEYRING_8       93
#define INVENTORY_KEYRING_9       94
#define INVENTORY_KEYRING_10         95
#define INVENTORY_KEYRING_11         96
#define INVENTORY_KEYRING_12         97
#define INVENTORY_KEYRING_13         98
#define INVENTORY_KEYRING_14         99
#define INVENTORY_KEYRING_15         100
#define INVENTORY_KEYRING_16         101
#define INVENTORY_KEYRING_17         102
#define INVENTORY_KEYRING_18         103
#define INVENTORY_KEYRING_19         104
#define INVENTORY_KEYRING_20         105
#define INVENTORY_KEYRING_21         106
#define INVENTORY_KEYRING_22         107
#define INVENTORY_KEYRING_23         108
#define INVENTORY_KEYRING_24         109
#define INVENTORY_KEYRING_25         110
#define INVENTORY_KEYRING_26         111
#define INVENTORY_KEYRING_27         112
#define INVENTORY_KEYRING_28         113
#define INVENTORY_KEYRING_29         114
#define INVENTORY_KEYRING_30         115
#define INVENTORY_KEYRING_31         116
#define INVENTORY_KEYRING_32         117
#define INVENTORY_KEYRING_END       118

#define CURRENCYTOKEN_SLOT_START    118
#define CURRENCYTOKEN_SLOT_1        118
#define CURRENCYTOKEN_SLOT_2        119
#define CURRENCYTOKEN_SLOT_3        120
#define CURRENCYTOKEN_SLOT_4        121
#define CURRENCYTOKEN_SLOT_5        122
#define CURRENCYTOKEN_SLOT_6        123
#define CURRENCYTOKEN_SLOT_7        124
#define CURRENCYTOKEN_SLOT_8        125
#define CURRENCYTOKEN_SLOT_9        126
#define CURRENCYTOKEN_SLOT_10       127
#define CURRENCYTOKEN_SLOT_11       128
#define CURRENCYTOKEN_SLOT_12       129
#define CURRENCYTOKEN_SLOT_13       130
#define CURRENCYTOKEN_SLOT_14       131
#define CURRENCYTOKEN_SLOT_15       132
#define CURRENCYTOKEN_SLOT_16       133
#define CURRENCYTOKEN_SLOT_17       134
#define CURRENCYTOKEN_SLOT_18       135
#define CURRENCYTOKEN_SLOT_19       136
#define CURRENCYTOKEN_SLOT_20       137
#define CURRENCYTOKEN_SLOT_21       138
#define CURRENCYTOKEN_SLOT_22       139
#define CURRENCYTOKEN_SLOT_23       140
#define CURRENCYTOKEN_SLOT_24       141
#define CURRENCYTOKEN_SLOT_25       142
#define CURRENCYTOKEN_SLOT_26       143
#define CURRENCYTOKEN_SLOT_27       144
#define CURRENCYTOKEN_SLOT_28       145
#define CURRENCYTOKEN_SLOT_29       146
#define CURRENCYTOKEN_SLOT_30       147
#define CURRENCYTOKEN_SLOT_31       148
#define CURRENCYTOKEN_SLOT_32       149
#define CURRENCYTOKEN_SLOT_END      150

enum INV_ERR
{
    INV_ERR_OK,
    INV_ERR_YOU_MUST_REACH_LEVEL_N,
    INV_ERR_SKILL_ISNT_HIGH_ENOUGH,
    INV_ERR_ITEM_DOESNT_GO_TO_SLOT,
    INV_ERR_BAG_FULL,
    INV_ERR_NONEMPTY_BAG_OVER_OTHER_BAG,
    INV_ERR_CANT_TRADE_EQUIP_BAGS,
    INV_ERR_ONLY_AMMO_CAN_GO_HERE,
    INV_ERR_NO_REQUIRED_PROFICIENCY,
    INV_ERR_NO_EQUIPMENT_SLOT_AVAILABLE,
    INV_ERR_YOU_CAN_NEVER_USE_THAT_ITEM,
    INV_ERR_YOU_CAN_NEVER_USE_THAT_ITEM2,
    INV_ERR_NO_EQUIPMENT_SLOT_AVAILABLE2,
    INV_ERR_CANT_EQUIP_WITH_TWOHANDED,
    INV_ERR_CANT_DUAL_WIELD,
    INV_ERR_ITEM_DOESNT_GO_INTO_BAG,
    INV_ERR_ITEM_DOESNT_GO_INTO_BAG2,
    INV_ERR_CANT_CARRY_MORE_OF_THIS,
    INV_ERR_NO_EQUIPMENT_SLOT_AVAILABLE3,
    INV_ERR_ITEM_CANT_STACK,
    INV_ERR_ITEM_CANT_BE_EQUIPPED,
    INV_ERR_ITEMS_CANT_BE_SWAPPED,
    INV_ERR_SLOT_IS_EMPTY,
    INV_ERR_ITEM_NOT_FOUND,
    INV_ERR_CANT_DROP_SOULBOUND,
    INV_ERR_OUT_OF_RANGE,
    INV_ERR_TRIED_TO_SPLIT_MORE_THAN_COUNT,
    INV_ERR_COULDNT_SPLIT_ITEMS,
    INV_ERR_MISSING_REAGENT,
    INV_ERR_NOT_ENOUGH_MONEY,
    INV_ERR_NOT_A_BAG,
    INV_ERR_CAN_ONLY_DO_WITH_EMPTY_BAGS,
    INV_ERR_DONT_OWN_THAT_ITEM,
    INV_ERR_CAN_EQUIP_ONLY1_QUIVER,
    INV_ERR_MUST_PURCHASE_THAT_BAG_SLOT,
    INV_ERR_TOO_FAR_AWAY_FROM_BANK,
    INV_ERR_ITEM_LOCKED,
    INV_ERR_YOU_ARE_STUNNED,
    INV_ERR_YOU_ARE_DEAD,
    INV_ERR_CANT_DO_RIGHT_NOW,
    INV_ERR_BAG_FULL2,
    INV_ERR_CAN_EQUIP_ONLY1_QUIVER2,
    INV_ERR_CAN_EQUIP_ONLY1_AMMOPOUCH,
    INV_ERR_STACKABLE_CANT_BE_WRAPPED,
    INV_ERR_EQUIPPED_CANT_BE_WRAPPED,
    INV_ERR_WRAPPED_CANT_BE_WRAPPED,
    INV_ERR_BOUND_CANT_BE_WRAPPED,
    INV_ERR_UNIQUE_CANT_BE_WRAPPED,
    INV_ERR_BAGS_CANT_BE_WRAPPED,
    INV_ERR_ALREADY_LOOTED,
    INV_ERR_INVENTORY_FULL,
    INV_ERR_BANK_FULL,
    INV_ERR_ITEM_IS_CURRENTLY_SOLD_OUT,
    INV_ERR_BAG_FULL3,
    INV_ERR_ITEM_NOT_FOUND2,
    INV_ERR_ITEM_CANT_STACK2,
    INV_ERR_BAG_FULL4,
    INV_ERR_ITEM_SOLD_OUT,
    INV_ERR_OBJECT_IS_BUSY,
    INV_ERR_NONE,
    INV_ERR_CANT_DO_IN_COMBAT,
    INV_ERR_CANT_DO_WHILE_DISARMED,
    INV_ERR_BAG_FULL6,
    INV_ERR_ITEM_RANK_NOT_ENOUGH,
    INV_ERR_ITEM_REPUTATION_NOT_ENOUGH,
    INV_ERR_MORE_THAN1_SPECIAL_BAG,
    INV_ERR_LOOT_CANT_LOOT_THAT_NOW,
    INV_ERR_ITEM_UNIQUE_EQUIPABLE,
    INV_ERR_VENDOR_MISSING_TURNINS,
    INV_ERR_NOT_ENOUGH_HONOR_POINTS,
    INV_ERR_NOT_ENOUGH_ARENA_POINTS,
    INV_ERR_ITEM_MAX_COUNT_SOCKETED,
    INV_ERR_MAIL_BOUND_ITEM,
    INV_ERR_NO_SPLIT_WHILE_PROSPECTING,
    INV_ERR_UNK,
    INV_ERR_ITEM_MAX_COUNT_EQUIPPED_SOCKETED,
    INV_ERR_ITEM_UNIQUE_EQUIPPABLE_SOCKETED,
    INV_ERR_TOO_MUCH_GOLD,
    INV_ERR_NOT_DURING_ARENA_MATCH,
    INV_ERR_CANNOT_TRADE_THAT,
    INV_ERR_PERSONAL_ARENA_RATING_TOO_LOW,
    INV_ERR_EVENT_AUTOEQUIP_BIND_CONFIRM,
    INV_ERR_ACCOUNT_BOUND,
    INV_ERR_OK2,
    INV_ERR_ITEM_MAX_LIMIT_CATEGORY_COUNT_EXCEEDED,
    INV_ERR_ITEM_MAX_LIMIT_CATEGORY_SOCKETED_EXCEEDED,
    INV_ERR_SCALING_STAT_ITEM_LEVEL_EXCEEDED,
    INV_ERR_PURCHASE_LEVEL_TOO_LOW,
    INV_ERR_CANT_EQUIP_NEED_TALENT,
    INV_ERR_ITEM_MAX_LIMIT_CATEGORY_EQUIPPED_EXCEEDED
};

enum ITEM_STAT_TYPE
{
    POWER     = 0,
    HEALTH   = 1,
    UNKNOWN = 2,
    AGILITY = 3,
    STRENGTH   = 4,
    INTELLECT  = 5,
    SPIRIT   = 6,
    STAMINA = 7,
    WEAPON_SKILL_RATING = 11,
    DEFENSE_RATING = 12,
    DODGE_RATING   = 13,
    PARRY_RATING   = 14,
    SHIELD_BLOCK_RATING = 15,
    MELEE_HIT_RATING    = 16,
    RANGED_HIT_RATING   = 17,
    SPELL_HIT_RATING    = 18,
    MELEE_CRITICAL_STRIKE_RATING = 19,
    RANGED_CRITICAL_STRIKE_RATING = 20,
    SPELL_CRITICAL_STRIKE_RATING  = 21,
    MELEE_HIT_AVOIDANCE_RATING  = 22,
    RANGED_HIT_AVOIDANCE_RATING   = 23,
    SPELL_HIT_AVOIDANCE_RATING  = 24,
    MELEE_CRITICAL_AVOIDANCE_RATING = 25,
    RANGED_CRITICAL_AVOIDANCE_RATING = 26,
    SPELL_CRITICAL_AVOIDANCE_RATING  = 27,
    MELEE_HASTE_RATING              = 28,
    RANGED_HASTE_RATING             = 29,
    SPELL_HASTE_RATING              = 30,
    HIT_RATING                      = 31,
    CRITICAL_STRIKE_RATING          = 32,
    HIT_AVOIDANCE_RATING            = 33,
    CRITICAL_AVOIDANCE_RATING       = 34,
    RESILIENCE_RATING               = 35,
    HASTE_RATING                    = 36,
    EXPERTISE_RATING                = 37,
    ATTACK_POWER                    = 38,
    RANGED_ATTACK_POWER             = 39,
    FERAL_ATTACK_POWER              = 40,
    SPELL_HEALING_DONE              = 41,
    SPELL_DAMAGE_DONE               = 42,
    MANA_REGENERATION               = 43,
    ARMOR_PENETRATION_RATING        = 44,
    SPELL_POWER                     = 45,
    HEALTH_REGEN                    = 46,
    SPELL_PENETRATION               = 47,
    BLOCK_VALUE                     = 48,
};


enum ITEM_DAMAGE_TYPE
{
    NORMAL_DAMAGE   = 0,
    HOLY_DAMAGE     = 1,
    FIRE_DAMAGE     = 2,
    NATURE_DAMAGE   = 3,
    FROST_DAMAGE    = 4,
    SHADOW_DAMAGE   = 5,
    ARCANE_DAMAGE   = 6,
};

enum ITEM_SPELLTRIGGER_TYPE
{
    USE             = 0,
    ON_EQUIP        = 1,
    CHANCE_ON_HIT   = 2,
    SOULSTONE       = 4,
    LEARNING        = 6,
};

enum ITEM_BONDING_TYPE
{
    ITEM_BIND_NONE      =   0,
    ITEM_BIND_ON_PICKUP =   1,
    ITEM_BIND_ON_EQUIP  =   2,
    ITEM_BIND_ON_USE    =   3,
    ITEM_BIND_QUEST     =   4,
    ITEM_BIND_QUEST2    =   5,
};

enum INVENTORY_TYPES
{
    INVTYPE_NON_EQUIP       = 0x0, // 0
    INVTYPE_HEAD            = 0x1, // 1
    INVTYPE_NECK            = 0x2, // 2
    INVTYPE_SHOULDERS       = 0x3, // 3
    INVTYPE_BODY            = 0x4, // 4
    INVTYPE_CHEST           = 0x5, // 5
    INVTYPE_WAIST           = 0x6, // 6 
    INVTYPE_LEGS            = 0x7, // 7
    INVTYPE_FEET            = 0x8, // 8
    INVTYPE_WRISTS          = 0x9, // 9
    INVTYPE_HANDS           = 0xa, // 10
    INVTYPE_FINGER          = 0xb, // 11
    INVTYPE_TRINKET         = 0xc, // 12
    INVTYPE_WEAPON          = 0xd, // 13
    INVTYPE_SHIELD          = 0xe, // 14
    INVTYPE_RANGED          = 0xf, // 15
    INVTYPE_CLOAK           = 0x10, //16
    INVTYPE_2HWEAPON        = 0x11, //17
    INVTYPE_BAG             = 0x12, //18
    INVTYPE_TABARD          = 0x13, //19
    INVTYPE_ROBE            = 0x14, //20
    INVTYPE_WEAPONMAINHAND  = 0x15, //21
    INVTYPE_WEAPONOFFHAND   = 0x16, //22
    INVTYPE_HOLDABLE        = 0x17, //23
    INVTYPE_AMMO            = 0x18, //24
    INVTYPE_THROWN          = 0x19, //25
    INVTYPE_RANGEDRIGHT     = 0x1a, //26
    INVTYPE_QUIVER          = 0x1b, //27
    INVTYPE_RELIC           = 0x1c, //28
    NUM_INVENTORY_TYPES     = 0x1d,
};

enum ITEM_CLASS
{
    ITEM_CLASS_CONSUMABLE   = 0,
    ITEM_CLASS_CONTAINER    = 1,
    ITEM_CLASS_WEAPON       = 2,
    ITEM_CLASS_JEWELRY      = 3,
    ITEM_CLASS_ARMOR        = 4,
    ITEM_CLASS_REAGENT      = 5,
    ITEM_CLASS_PROJECTILE   = 6,
    ITEM_CLASS_TRADEGOODS   = 7,
    ITEM_CLASS_GENERIC      = 8,
    ITEM_CLASS_RECIPE       = 9,
    ITEM_CLASS_MONEY        = 10,
    ITEM_CLASS_QUIVER       = 11,
    ITEM_CLASS_QUEST        = 12,
    ITEM_CLASS_KEY          = 13,
    ITEM_CLASS_PERMANENT    = 14,
    ITEM_CLASS_MISCELLANEOUS= 15,
    ITEM_CLASS_GLYPHS       = 16,
};

enum Item_Subclass
{
   // Weapon
   ITEM_SUBCLASS_WEAPON_AXE                 = 0,
   ITEM_SUBCLASS_WEAPON_TWOHAND_AXE         = 1,
   ITEM_SUBCLASS_WEAPON_BOW                 = 2,
   ITEM_SUBCLASS_WEAPON_GUN                 = 3,
   ITEM_SUBCLASS_WEAPON_MACE                = 4,
   ITEM_SUBCLASS_WEAPON_TWOHAND_MACE        = 5,
   ITEM_SUBCLASS_WEAPON_POLEARM             = 6,
   ITEM_SUBCLASS_WEAPON_SWORD               = 7,
   ITEM_SUBCLASS_WEAPON_TWOHAND_SWORD       = 8,
   ITEM_SUBCLASS_WEAPON_STAFF               = 10,
   ITEM_SUBCLASS_WEAPON_EXOTIC              = 11,
   ITEM_SUBCLASS_WEAPON_EXOTIC2             = 12,
   ITEM_SUBCLASS_WEAPON_FIST_WEAPON         = 13,
   ITEM_SUBCLASS_WEAPON_MISC_WEAPON         = 14,
   ITEM_SUBCLASS_WEAPON_DAGGER              = 15,
   ITEM_SUBCLASS_WEAPON_THROWN              = 16,
   ITEM_SUBCLASS_WEAPON_SPEAR               = 17,
   ITEM_SUBCLASS_WEAPON_CROSSBOW            = 18,
   ITEM_SUBCLASS_WEAPON_WAND                = 19,
   ITEM_SUBCLASS_WEAPON_FISHING_POLE        = 20,

   // Armor
   ITEM_SUBCLASS_ARMOR_MISC                 = 0,
   ITEM_SUBCLASS_ARMOR_CLOTH                = 1,
   ITEM_SUBCLASS_ARMOR_LEATHER              = 2,
   ITEM_SUBCLASS_ARMOR_MAIL                 = 3,
   ITEM_SUBCLASS_ARMOR_PLATE_MAIL           = 4,
   ITEM_SUBCLASS_ARMOR_BUCKLER              = 5,
   ITEM_SUBCLASS_ARMOR_SHIELD               = 6,
   ITEM_SUBCLASS_ARMOR_LIBRAM               = 7,
   ITEM_SUBCLASS_ARMOR_IDOL                 = 8,
   ITEM_SUBCLASS_ARMOR_TOTEM                = 9,
   ITEM_SUBCLASS_ARMOR_SIGIL                = 10,

   // Projectile
   ITEM_SUBCLASS_PROJECTILE_WAND            = 0,
   ITEM_SUBCLASS_PROJECTILE_BOLT            = 1,
   ITEM_SUBCLASS_PROJECTILE_ARROW           = 2,
   ITEM_SUBCLASS_PROJECTILE_BULLET          = 3,
   ITEM_SUBCLASS_PROJECTILE_THROWN          = 4,

   // Recipe
   ITEM_SUBCLASS_RECIPE_BOOK                = 0,
   ITEM_SUBCLASS_RECIPE_LEATHERWORKING      = 1,
   ITEM_SUBCLASS_RECIPE_TAILORING           = 2,
   ITEM_SUBCLASS_RECIPE_ENGINEERING         = 3,
   ITEM_SUBCLASS_RECIPE_BLACKSMITHING       = 4,
   ITEM_SUBCLASS_RECIPE_COOKING             = 5,
   ITEM_SUBCLASS_RECIPE_ALCHEMY             = 6,
   ITEM_SUBCLASS_RECIPE_FIRST_AID           = 7,
   ITEM_SUBCLASS_RECIPE_ENCHANTING          = 8,
   ITEM_SUBCLASS_RECIPE_FISHING             = 9,
   ITEM_SUBCLASS_RECIPE_JEWELCRAFTING       = 10,
   ITEM_SUBCLASS_RECIPE_INSCRIPTION         = 11, //Guessed

   // Quiver
   ITEM_SUBCLASS_QUIVER_QUIVER              = 2,
   ITEM_SUBCLASS_QUIVER_AMMO_POUCH          = 3,

   // Containers
   ITEM_SUBCLASS_CONTAINER                  = 0,
   ITEM_SUBCLASS_CONTAINER_SOUL             = 1,
   ITEM_SUBCLASS_CONTAINER_HERB             = 2,
   ITEM_SUBCLASS_CONTAINER_ENCHANTING       = 3,
   ITEM_SUBCLASS_CONTAINER_ENGINEERING      = 4,
   ITEM_SUBCLASS_CONTAINER_GEM              = 5,
   ITEM_SUBCLASS_CONTAINER_MINING           = 6,
   ITEM_SUBCLASS_CONTAINER_LEATHERWORKING   = 7,
   ITEM_SUBCLASS_CONTAINER_INSCRIPTION      = 8,

   // Consumable
   ITEM_SUBCLASS_CONSUMABLE                 = 0,
   ITEM_SUBCLASS_CONSUMABLE_POTION          = 1,
   ITEM_SUBCLASS_CONSUMABLE_ELIXIR          = 2,
   ITEM_SUBCLASS_CONSUMABLE_FLASK           = 3,
   ITEM_SUBCLASS_CONSUMABLE_SCROLL          = 4,
   ITEM_SUBCLASS_CONSUMABLE_FOOD            = 5,
   ITEM_SUBCLASS_CONSUMABLE_ITEM_ENCHANT    = 6,
   ITEM_SUBCLASS_CONSUMABLE_BANDAGE         = 7,
   ITEM_SUBCLASS_CONSUMABLE_OTHER           = 8,

   // Gem
   ITEM_SUBCLASS_GEM_RED                    = 0,
   ITEM_SUBCLASS_GEM_BLUE                   = 1,
   ITEM_SUBCLASS_GEM_YELLOW                 = 2,
   ITEM_SUBCLASS_GEM_PURPLE                 = 3,
   ITEM_SUBCLASS_GEM_GREEN                  = 4,
   ITEM_SUBCLASS_GEM_ORANGE                 = 5,
   ITEM_SUBCLASS_GEM_META                   = 6,
   ITEM_SUBCLASS_GEM_SIMPLE                 = 7,
   ITEM_SUBCLASS_GEM_PRISMATIC              = 8,

   // Trade goods
   ITEM_SUBCLASS_TRADE_GOODS                = 0,
   ITEM_SUBCLASS_PROJECTILE_PARTS           = 1,
   ITEM_SUBCLASS_PROJECTILE_EXPLOSIVES      = 2,
   ITEM_SUBCLASS_PROJECTILE_DEVICES         = 3,
   ITEM_SUBCLASS_JEWELCRAFTING              = 4,
   ITEM_SUBCLASS_CLOTH                      = 5,
   ITEM_SUBCLASS_LEATHER                    = 6,
   ITEM_SUBCLASS_METAL_STONE                = 7,
   ITEM_SUBCLASS_MEAT                       = 8,
   ITEM_SUBCLASS_HERB                       = 9,
   ITEM_SUBCLASS_ELEMENTAL                  = 10,
   ITEM_SUBCLASS_TRADE_GOODS_OTHER          = 11,
   ITEM_SUBCLASS_ENCHANTING                 = 12,
   ITEM_SUBCLASS_MATERIAL                   = 13,
   ITEM_SUBCLASS_ARMOR_ENCHANTMENT          = 14,
   ITEM_SUBCLASS_WEAPON_ENCHANTMENT         = 15,

   //Glyph
   ITEM_SUBCLASS_GLYPH_WARRIOR              = 1,
   ITEM_SUBCLASS_GLYPH_PALADIN              = 2,
   ITEM_SUBCLASS_GLYPH_HUNTER               = 3,
   ITEM_SUBCLASS_GLYPH_ROGUE                = 4,
   ITEM_SUBCLASS_GLYPH_PRIEST               = 5,
   ITEM_SUBCLASS_GLYPH_DEATH_KNIGHT         = 6,
   ITEM_SUBCLASS_GLYPH_SHAMAN               = 7,
   ITEM_SUBCLASS_GLYPH_MAGE                 = 8,
   ITEM_SUBCLASS_GLYPH_WARLOCK              = 9,
   ITEM_SUBCLASS_GLYPH_DRUID                = 11,

   // Key
   ITEM_SUBCLASS_KEY                        = 0,
   ITEM_SUBCLASS_LOCKPICK                   = 1,

   // MISCELLANEOUS
   ITEM_SUBCLASS_MISCELLANEOUS              = 0,
   ITEM_SUBCLASS_MISCELLANEOUS_REAGENT      = 1,
   ITEM_SUBCLASS_MISCELLANEOUS_PET          = 2,
   ITEM_SUBCLASS_MISCELLANEOUS_HOLIDAY      = 3,
   ITEM_SUBCLASS_MISCELLANEOUS_OTHER        = 4,
   ITEM_SUBCLASS_MISCELLANEOUS_MOUNT        = 5,
};

enum ITEM_QUALITY
{
    ITEM_QUALITY_POOR_GREY             = 0,
    ITEM_QUALITY_NORMAL_WHITE          = 1,
    ITEM_QUALITY_UNCOMMON_GREEN        = 2,
    ITEM_QUALITY_RARE_BLUE             = 3,
    ITEM_QUALITY_EPIC_PURPLE           = 4,
    ITEM_QUALITY_LEGENDARY_ORANGE      = 5,
    ITEM_QUALITY_ARTIFACT_LIGHT_YELLOW = 6,
};

enum ITEM_FLAG
{
    ITEM_FLAG_SOULBOUND     = 0x1,      // not used in proto
    ITEM_FLAG_CONJURED      = 0x2,
    ITEM_FLAG_LOOTABLE      = 0x4,
    ITEM_FLAG_WRAPPED       = 0x8,      // not used in proto
    ITEM_FLAG_UNKNOWN_05    = 0x10,     // many equipable items and bags
    ITEM_FLAG_UNKNOWN_06    = 0x20,     // totems
    ITEM_FLAG_UNKNOWN_07    = 0x40,     // many consumables
    ITEM_FLAG_UNKNOWN_08    = 0x80,     // only 1 wand uses this
    ITEM_FLAG_UNKNOWN_09    = 0x100,    // some wands & relics
    ITEM_FLAG_WRAP_GIFT     = 0x200,
    ITEM_FLAG_CREATE_ITEM   = 0x400,
    ITEM_FLAG_QUEST         = 0x800,
    ITEM_FLAG_UNKNOWN_13    = 0x1000,   // not used in proto
    ITEM_FLAG_SIGNABLE      = 0x2000,
    ITEM_FLAG_READABLE      = 0x4000,
    ITEM_FLAG_UNKNOWN_16    = 0x8000,
    ITEM_FLAG_EVENT_REQ     = 0x10000,
    ITEM_FLAG_UNKNOWN_18    = 0x20000,
    ITEM_FLAG_PROSPECTABLE  = 0x40000,
    ITEM_FLAG_UNIQUE_EQUIP  = 0x80000,
    ITEM_FLAG_UNKNOWN_21    = 0x100000, // not used in proto
    ITEM_FLAG_UNKNOWN_22    = 0x200000, // player created health/mana
    ITEM_FLAG_THROWN        = 0x400000,
    ITEM_FLAG_SHAPESHIFT_OK = 0x800000,
    ITEM_FLAG_BINDONACC     = 0x8000000, // bind on account
    ITEM_FLAG_MILLABLE      = 0x20000000
};

enum SPECIAL_ITEM_TYPE
{
    ITEM_TYPE_BOWAMMO       = 1,    // Arrows
    ITEM_TYPE_GUNAMMO       = 2,    // Bullets
    ITEM_TYPE_SOULSHARD     = 4,    // Soul Shards
    ITEM_TYPE_LEATHERWORK   = 8,    // Leatherworking Supplies
    ITEM_TYPE_INSCRIPTION   = 16,   // Inscripton Supplies
    ITEM_TYPE_HERBALISM     = 32,   // Herbs
    ITEM_TYPE_ENCHANTMENT   = 64,   // Enchanting Supplies
    ITEM_TYPE_ENGINEERING   = 128,  // Engineering Supplies
    ITEM_TYPE_KEYRING       = 256,  // Keys
    ITEM_TYPE_GEMS          = 512,  // Gems
    ITEM_TYPE_MINING        = 1024, // Mining Supplies
    ITEM_TYPE_SBEQUIPMENT   = 2048, // Soulbound Equipment
    ITEM_TYPE_VANITYPETS    = 4096, // Vanity Pets
    ITEM_TYPE_CURRENCY      = 8192,
    ITEM_TYPE_QUEST_ITEMS   = 16384
};

enum SOCKET_GEM_COLOR
{
    META_SOCKET = 1,
    RED_SOCKET = 2,
    YELLOW_SOCKET = 4,
    BLUE_SOCKET = 8
};

#pragma pack(PRAGMA_PACK)
struct SocketInfo
{
    uint32 SocketColor;
    uint32 Unk;
};

struct ItemSpell
{
    int32 Id;
    int32 Trigger;
    int32 Charges;
    int32 Cooldown;
    int32 Category;
    int32 CategoryCooldown;
};

struct ItemDamage
{
    float Min;
    float Max;
    uint32 Type;
};

struct ItemStat
{
    uint32 Type;
    int32 Value;
};

struct ItemPrototype
{
    uint32 ItemId;
    int32 Class;
    int32 SubClass;
    int32 unknown_bc;
    char * Name1;
    uint32 DisplayInfoID;
    int32 Quality;
    uint32 Flags;
    int32 Faction;
    uint32 BuyPrice;
    uint32 SellPrice;
    int32 InventoryType;
    int32 AllowableClass;
    int32 AllowableRace;
    int32 ItemLevel;
    int32 RequiredLevel;
    int32 RequiredSkill;
    int32 RequiredSkillRank;
    int32 RequiredSpell;
    int32 RequiredPlayerRank1;
    int32 RequiredPlayerRank2;
    int32 RequiredFaction;
    int32 RequiredFactionStanding;
    int32 Unique;
    int32 MaxCount;
    int32 ContainerSlots;
    ItemStat Stats[10];
    int32 ScalingStatsEntry;
    int32 ScalingStatsFlag;
    ItemDamage Damage[2];
    int32 Armor;
    int32 HolyRes;
    int32 FireRes;
    int32 NatureRes;
    int32 FrostRes;
    int32 ShadowRes;
    int32 ArcaneRes;
    int32 Delay;
    int32 AmmoType;
    float  Range;
    ItemSpell Spells[5];
    int32 Bonding;
    char * Description;
    int32 PageId;
    int32 PageLanguage;
    int32 PageMaterial;
    int32 QuestId;
    int32 LockId;
    int32 LockMaterial;
    int32 SheathId;
    int32 RandomPropId;
    int32 RandomSuffixId;
    int32 Block;
    int32 ItemSet;
    int32 MaxDurability;
    int32 ZoneNameID;
    int32 MapID;
    int32 BagFamily;
    int32 TotemCategory;
    SocketInfo Sockets[3];
    int32 SocketBonus;
    int32 GemProperties;
    int32 DisenchantReqSkill;
    int32 Lootgold;
    int32 ArmorDamageModifier;
    int32 ItemLimitCategory;
    int32 HolidayId;

    uint32 FoodType;        //pet food type
    int32 ForcedPetId;
    uint32 DummySubClass;
    uint32 ItemSetRank;

    string ConstructItemLink(uint32 random_prop, uint32 random_suffix, uint32 stack);
    bool ValidateItemLink(const char *szLink);
    bool ValidateItemSpell(uint32 SpellID);
    char* CreateInsertString();
};

typedef struct
{
    uint32 setid;
    uint32 itemscount;
    //Spell* spell[8];
}ItemSet;

#pragma pack(PRAGMA_POP)
