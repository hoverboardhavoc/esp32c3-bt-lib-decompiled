/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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

