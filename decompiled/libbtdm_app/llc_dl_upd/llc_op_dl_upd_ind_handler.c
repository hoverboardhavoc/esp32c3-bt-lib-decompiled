/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llc_dl_upd.o -> llc_op_dl_upd_ind_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 llc_op_dl_upd_ind_handler(int param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  param_2 = param_2 >> 8;
  iVar1 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  if (((param_2 < *(byte *)(iVar1 + 0xd)) && (*(int *)(&llc_env + param_2 * 4) != 0)) &&
     ((*(byte *)(*(int *)(&llc_env + param_2 * 4) + 0x44) & 3) != 3)) {
    uVar2 = 2;
    iVar1 = (**(code **)(_r_ip_funcs_p + 0x678))(param_2,0,*(code **)(_r_ip_funcs_p + 0x678));
    if (iVar1 == 0) {
      uVar2 = 1;
      (**(code **)(_r_ip_funcs_p + 0x67c))(param_2,0,param_1,*(code **)(_r_ip_funcs_p + 0x67c));
      (**(code **)(_r_ip_funcs_p + 0x5d4))(param_2,0,*(code **)(_r_ip_funcs_p + 0x5d4));
    }
  }
  else {
    uVar2 = 0;
    if (*(char *)(param_1 + 0x10) != '\0') {
      (**(code **)(_r_ip_funcs_p + 0x5d0))
                (param_2,*(undefined1 *)(*(int *)(&llc_env + param_2 * 4) + 0x46),0,0,0,0,
                 *(code **)(_r_ip_funcs_p + 0x5d0));
    }
  }
  return uVar2;
}

