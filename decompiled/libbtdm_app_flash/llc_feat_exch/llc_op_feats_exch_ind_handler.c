/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
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
    uVar2 = 0;
    if (*(char *)(param_1 + 8) != '\0') {
      r_llc_hci_feats_info_send
                (param_2,*(undefined1 *)(*(int *)(&llc_env + param_2 * 4) + 0x46),
                 *(int *)(&llc_env + param_2 * 4) + 0x30);
    }
  }
  return uVar2;
}

