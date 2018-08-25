/*
__builtin_ffs(x)：返回x中最后一个为1的位是从后向前的第几位，如__builtin_ffs(0x789)=1, __builtin_ffs(0x78c)=3。于是，__builtin_ffs(x) - 1就是x中最后一个为1的位的位置。

__builtin_popcount(x)：x中1的个数。

__builtin_ctz(x)：x末尾0的个数。x=0时结果未定义。

__builtin_clz(x)：x前导0的个数。x=0时结果未定义。
上面的宏中x都是unsigned int型的，如果传入signed或者是char型，会被强制转换成unsigned int。

__builtin_parity(x)：x中1的奇偶性。

__builtin_return_address(n)：当前函数的第n级调用者的地址，用的最多的就是__builtin_return_address(0)，即获得当前函数的调用者的地址。注意，该函数实现是体系结构相关的，有些体系结构只实现了n=0的返回结果。

uint16_t __builtin_bswap16 (uint16_t x)
uint32_t __builtin_bswap32 (uint32_t x)：按字节翻转x，返回翻转后的结果。

__builtin_prefetch (const void *addr, ...)：它通过对数据手工预取的方法，在使用地址addr的值之前就将其放到cache中，减少了读取延迟，从而提高了性能，但该函数也需要 CPU 的支持。该函数可接受三个参数，第一个参数addr是要预取的数据的地址，第二个参数可设置为0或1（1表示我对地址addr要进行写操作，0表示要进行读操作），第三个参数可取0-3（0表示不用关心时间局部性，取完addr的值之后便不用留在cache中，而1、2、3表示时间局部性逐渐增强）。

__builtin_constant_p (exp)：判断exp是否在编译时就可以确定其为常量，如果exp为常量，该函数返回1，否则返回0。如果exp为常量，可以在代码中做一些优化来减少处理exp的复杂度。

__builtin_types_compatible_p(type1, type2)：判断type1和type2是否是相同的数据类型，相同返回1，否则返回0。该函数不区分const/volatile这样的修饰符，即int和const int被认为是相同的类型。
*/
