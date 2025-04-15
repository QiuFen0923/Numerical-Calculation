### 2.1 求正弦函数值 & 2.2 求余弦函数值

这两题均利用了泰勒级数展开及Horner's Method（一种能加速多项式运算的反向运算）

以下是sin(x)和cos(x)的泰勒展开式：

$$
\sin(x) = \sum_{k=0}^{\infty} (-1)^k \frac{x^{2k+1}}{(2k+1)!} = x - \frac{x^3}{3!} + \frac{x^5}{5!} - \frac{x^7}{7!} + \cdots
$$

$$
\cos(x) = \sum_{k=0}^{\infty} (-1)^k \frac{x^{2k}}{(2k)!} = 1 - \frac{x^2}{2!} + \frac{x^4}{4!} - \frac{x^6}{6!} + \cdots
$$

以sin(x)的泰勒展开式举例：

$$
\sin(x) = x \Bigg( 1 - \frac{x^2}{3 \cdot 2} \bigg( 1 - \frac{x^2}{5 \cdot 4} \Big( 1 - \frac{x^2}{7 \cdot 6} \big( \cdots \big) \Big) \bigg) \Bigg)
$$

$$
y = 1 - y \cdot \frac{x^2}{K \cdot (K+1)}
$$

其中K是计算 sin(x) 所需的泰勒展开项数 N的2倍，用于记录分母

我们以这个形式递推，最后得到 y*x 即可
