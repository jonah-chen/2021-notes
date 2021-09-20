module mycompare (x2, x1, x0, f);
    input x2, x1, x0;
    output f;
    assign f = x2 & (x1 | x0);
endmodule