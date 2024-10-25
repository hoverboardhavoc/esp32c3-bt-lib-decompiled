/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llc_disconnect.o -> llc_op_disconnect_ind_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 llc_op_disconnect_ind_handler(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  param_2 = param_2 >> 8;
  iVar4 = *(int *)(&llc_env + param_2 * 4);
  iVar2 = r_sdk_config_get_opts();
  uVar1 = param_2 & 0xff;
  uVar3 = 0;
  if (((uVar1 < *(byte *)(iVar2 + 0xd)) && (iVar2 = *(int *)(&llc_env + param_2 * 4), iVar2 != 0))
     && ((*(byte *)(iVar2 + 0x44) & 3) != 3)) {
    uVar3 = 2;
    if ((*(ushort *)(iVar4 + 0x42) & 0x200) == 0) {
      iVar2 = r_llc_proc_id_get(uVar1,0);
      if (iVar2 != 0) {
        r_llc_proc_err_ind(uVar1,0,0,param_1 + 9);
        iVar2 = r_llc_proc_id_get(uVar1,0);
        if (iVar2 != 0) {
          uVar3 = r_llc_proc_id_get(uVar1,0);
          r_assert_param(param_2,uVar3,"llc_disconnect.c",0x1c8);
        }
      }
      r_llc_proc_reg(uVar1,0,param_1);
      r_llc_disconnect_proc_continue(uVar1,0);
      uVar3 = 1;
    }
  }
  return uVar3;
}

