/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llc_le_ping.o -> f_llc_op_le_ping_ind_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 f_llc_op_le_ping_ind_handler(undefined4 param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  param_2 = param_2 >> 8;
  iVar1 = r_sdk_config_get_opts();
  uVar2 = 0;
  if (((param_2 < *(byte *)(iVar1 + 0xd)) && (*(int *)(&llc_env + param_2 * 4) != 0)) &&
     ((*(byte *)(*(int *)(&llc_env + param_2 * 4) + 0x44) & 3) != 3)) {
    iVar1 = r_llc_proc_id_get(param_2,0);
    uVar2 = 2;
    if (iVar1 == 0) {
      r_llc_proc_reg(param_2,0,param_1);
      r_llc_le_ping_proc_continue(param_2,0,0);
      uVar2 = 1;
    }
  }
  return uVar2;
}

