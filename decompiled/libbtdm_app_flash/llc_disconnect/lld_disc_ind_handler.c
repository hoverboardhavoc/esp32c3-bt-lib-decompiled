/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llc_disconnect.o -> lld_disc_ind_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 lld_disc_ind_handler(char *param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  
  param_2 = param_2 >> 8;
  iVar1 = *(int *)(&llc_env + param_2 * 4);
  uVar2 = param_2 & 0xff;
  if (iVar1 == 0) {
    r_assert_param(param_2,0,"llc_disconnect.c",0x15f);
  }
  if (*param_1 != '\x16') {
    *(char *)(iVar1 + 0x46) = *param_1;
    *(undefined1 *)(iVar1 + 0x47) = 0;
  }
  *(undefined1 *)(iVar1 + 0x49) = 1;
  r_llc_proc_err_ind(uVar2,0,0,iVar1 + 0x46);
  iVar3 = r_llc_proc_id_get(uVar2,0);
  if (iVar3 != 0) {
    uVar4 = r_llc_proc_id_get(uVar2,0);
    r_assert_param(param_2,uVar4,"llc_disconnect.c",0x16b);
  }
  r_llc_proc_err_ind(uVar2,1,0,iVar1 + 0x46);
  iVar1 = r_llc_proc_id_get(uVar2,1);
  if (iVar1 != 0) {
    uVar4 = r_llc_proc_id_get(uVar2,1);
    r_assert_param(param_2,uVar4,"llc_disconnect.c",0x16e);
  }
  r_llc_stop(uVar2);
  return 0;
}

