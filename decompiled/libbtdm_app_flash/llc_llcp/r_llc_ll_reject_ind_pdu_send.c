/*
 * Last changed at upstream commit d2414a5dd958b32ca53382b441d24d97a0345a55
 * https://github.com/espressif/esp32c3-bt-lib/commit/d2414a5dd958b32ca53382b441d24d97a0345a55
 * Upstream date: 2025-03-20 20:11:19 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(03d0f8a6)
 * Source: libbtdm_app_flash -> llc_llcp.o -> r_llc_ll_reject_ind_pdu_send
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_llc_ll_reject_ind_pdu_send(uint param_1,uint param_2,undefined1 param_3,undefined4 param_4)

{
  int iVar1;
  undefined1 uStack_14;
  undefined1 uStack_13;
  undefined1 uStack_12;
  
  iVar1 = r_sdk_config_get_opts();
  if ((((param_1 < *(byte *)(iVar1 + 0xd)) && (*(int *)(&llc_env + param_1 * 4) != 0)) &&
      (((int)(uint)*(byte *)(*(int *)(&llc_env + param_1 * 4) + 0x30) >> 2 & 1U) != 0)) ||
     (0xd < param_2)) {
    uStack_14 = 0x11;
    uStack_13 = (undefined1)param_2;
    uStack_12 = param_3;
  }
  else {
    uStack_14 = 0xd;
    uStack_13 = param_3;
  }
  r_llc_llcp_send_eco(param_1,&uStack_14,param_4);
  return;
}

