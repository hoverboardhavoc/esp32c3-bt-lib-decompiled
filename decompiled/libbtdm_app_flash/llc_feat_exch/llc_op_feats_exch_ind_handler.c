/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llc_feat_exch.o -> llc_op_feats_exch_ind_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 llc_op_feats_exch_ind_handler(int param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  param_2 = param_2 >> 8;
  iVar1 = r_sdk_config_get_opts();
  if (((param_2 < *(byte *)(iVar1 + 0xd)) && (*(int *)(&llc_env + param_2 * 4) != 0)) &&
     ((*(byte *)(*(int *)(&llc_env + param_2 * 4) + 0x44) & 3) != 3)) {
    iVar1 = r_llc_proc_id_get(param_2,0);
    uVar2 = 2;
    if (iVar1 == 0) {
      r_llc_proc_reg(param_2,0,param_1);
      r_llc_loc_feats_exch_proc_continue(param_2,0);
      uVar2 = 1;
    }
  }
  else {
    if (*(char *)(param_1 + 8) != '\0') {
      r_llc_hci_feats_info_send
                (param_2,*(undefined1 *)(*(int *)(&llc_env + param_2 * 4) + 0x46),
                 *(int *)(&llc_env + param_2 * 4) + 0x30);
    }
    uVar2 = 0;
  }
  return uVar2;
}

