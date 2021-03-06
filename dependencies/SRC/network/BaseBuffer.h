/***
 * Demonstrike Core
 */

#pragma once

class SERVER_DECL BaseBuffer
{
public:
    /** Destructor
     */
    virtual ~BaseBuffer() {}

    /** Allocate the buffer with room for size bytes
     * @param size the number of bytes to allocate
     */
    virtual void Allocate(size_t size) = 0;

    /** Write bytes to the buffer
     * @param data pointer to the data to be written
     * @param bytes number of bytes to be written
     * @return true if was successful, otherwise false
     */
    virtual bool Write(const void * data, size_t bytes) = 0;

    /** Read bytes from the buffer
     * @param destination pointer to destination where bytes will be written
     * @param bytes number of bytes to read
     * @return true if there was enough data, false otherwise
     */
    virtual bool Read(void * destination, size_t bytes) = 0;

    /** Returns a pointer at the "end" of the buffer, where new data can be written
     */
    virtual void * GetBuffer() = 0;

    /** Returns a pointer at the "beginning" of the buffer, where data can be pulled from
     */
    virtual void * GetBufferOffset() = 0;

    /** Returns the number of available bytes left.
     */
    virtual size_t GetSpace() = 0;

    /** Increments the "writen" pointer forward len bytes
     * @param len number of bytes to step
     */
    virtual void IncrementWritten(size_t len) = 0;

    /** Returns the number of bytes currently stored in the buffer.
     */
    virtual size_t GetSize() = 0;

    /** Removes len bytes from the front of the buffer
     * @param len the number of bytes to "cut"
     */
    virtual void Remove(size_t len) = 0;
};
