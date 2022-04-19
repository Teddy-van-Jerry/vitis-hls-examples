/**
 * File:    helloworld_ip_tb.v
 * Brief:   helloworld ip test
 * Author:  Wuqiong Zhao
 * Version: 1.0 (2022-04-18)
 */

`timescale 1ns / 1ps

module HELLOWORLD_IP_TB();

    parameter   CYC         = 10;
    parameter   DELAY       = 1;
    parameter   START_TIME  = CYC;
    parameter   FINISH_TIME = 40 * CYC;
    reg         Clk = 0;

    // Input
    reg         Start       = 0;
    reg  [31:0] Data_in     = 0;
    // Output
    wire        Vld;
    wire [31:0] Data_out;
        
    HELLO_WORLD Uhelloworld (
        .b_ap_vld (Vld     ),  // output wire b_ap_vld
        .ap_start (Start   ),  // input wire ap_start
        .ap_done  (        ),  // output wire ap_done
        .ap_idle  (        ),  // output wire ap_idle
        .ap_ready (        ),  // output wire ap_ready
        .a        (Data_in ),  // input wire [31 : 0] a
        .b        (Data_out)   // output wire [31 : 0] b
    );

    initial begin
        #START_TIME  Start <= 1'b1;
        #FINISH_TIME $finish;
    end
    
    always #CYC Clk = ~Clk;
    
    always @(posedge Clk) begin
        #DELAY Data_in = Data_in + 1;    // increment one each clock
        #DELAY $display("Data Out: %b", Data_out); // display result
    end
    
endmodule // of HELLOWORLD_IP_TB
