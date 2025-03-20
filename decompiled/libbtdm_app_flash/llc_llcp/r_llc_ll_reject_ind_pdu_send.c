/*
 * Last changed at upstream commit aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * https://github.com/espressif/esp32c3-bt-lib/commit/aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * Upstream date: 2025-03-20 20:31:24 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(d74042a8)
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
  r_llc_llcp_send(param_1,&uStack_14,param_4);
  return;
}

