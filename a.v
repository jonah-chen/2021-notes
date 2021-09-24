module mycompare (x2, x1, x0, f);
    input x2, x1, x0;
    output f;
    assign f = x2 & (x1 | x0);
endmodule

/* hierarctical (aka structural verilog) implementation of 4to1 mux */

module mux2to1 (
    a, b, s, f
);
    input a,b,s;
    output f;
    assign f = (~s&a)|(s&b);
endmodule

module mux4to1 (
    a,b,c,d,s0,s1,f
);
    input a,b,c,d,s0,s1;
    output f;
    wire w0,w1;

    mux2to1 u2(w0,w1,s1,f);
    mux2to1 u0(a,b,s0,w0);
    mux2to1 u1(c,d,s1,w1); // the order of these lines doesn't matter
endmodule

module muxor (
    a,b,f
);
    mux2to1(b,1,a,f);
endmodule

module muxand (
    a,b,f
);
    mux2to1(0,b,a,f);
endmodule

module muxnot (
    a,f
);
    mux2to1(1,0,a,f);
endmodule
