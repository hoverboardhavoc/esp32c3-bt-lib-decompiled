/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llc_encrypt.o -> ll_enc_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 ll_enc_rsp_handler(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar1 + 0x20) == '\0') {
    return 0x24;
  }
  if ((*(ushort *)(*(int *)(&llc_env + param_1 * 4) + 0x42) & 1) == 0) {
    iVar1 = r_llc_proc_id_get(1);
    if (iVar1 == 3) {
      r_llc_rem_encrypt_proc_continue_eco(param_1,0x13,0x3d);
      return 0;
    }
  }
  else {
    iVar1 = r_llc_proc_id_get(0,param_3);
    if (iVar1 == 3) {
      iVar1 = r_llc_proc_get(param_1,0);
      memcpy((void *)(iVar1 + 0x24),(void *)(param_2 + 9),4);
      memcpy((void *)(iVar1 + 0x30),(void *)(param_2 + 1),8);
      r_llc_loc_encrypt_proc_continue(param_1,4,0);
      return 0;
    }
  }
  return 0x24;
}

