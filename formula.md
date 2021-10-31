


$$P(C,i) =
\begin{cases}
                          0 & \text{if $C=0$ or $i=0$} \\
                          P(C,i-1)& \text{if $C<w_{i}$} \\
max(P(C,i-1), p_{i}+P(C-w_{i}, i)) & \text{if C$\geq w_{i}$} 
\end{cases}$$