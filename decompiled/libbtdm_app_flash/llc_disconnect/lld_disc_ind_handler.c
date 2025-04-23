/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llc_disconnect.o -> lld_disc_ind_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 lld_disc_ind_handler(char *param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  param_2 = param_2 >> 8;
  iVar1 = *(int *)(&llc_env + param_2 * 4);
  if (iVar1 == 0) {
    r_assert_param(param_2,0,"llc_disconnect.c",0x15f);
  }
  if (*param_1 != '\x16') {
    *(char *)(iVar1 + 0x46) = *param_1;
    *(undefined1 *)(iVar1 + 0x47) = 0;
  }
  *(undefined1 *)(iVar1 + 0x49) = 1;
  r_llc_proc_err_ind(param_2,0,0,iVar1 + 0x46);
  iVar2 = r_llc_proc_id_get(param_2,0);
  if (iVar2 != 0) {
    uVar3 = r_llc_proc_id_get(param_2,0);
    r_assert_param(param_2,uVar3,"llc_disconnect.c",0x16b);
  }
  r_llc_proc_err_ind(param_2,1,0,iVar1 + 0x46);
  iVar1 = r_llc_proc_id_get(param_2,1);
  if (iVar1 != 0) {
    uVar3 = r_llc_proc_id_get(param_2,1);
    r_assert_param(param_2,uVar3,"llc_disconnect.c",0x16e);
  }
  r_llc_stop(param_2);
  return 0;
}

