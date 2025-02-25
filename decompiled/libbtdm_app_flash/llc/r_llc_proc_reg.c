/*
 * Last changed at upstream commit 2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * https://github.com/espressif/esp32c3-bt-lib/commit/2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * Upstream date: 2025-02-25 15:16:47 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(723439d)
 * Source: libbtdm_app_flash -> llc.o -> r_llc_proc_reg
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_llc_proc_reg(uint param_1,uint param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  
  uVar2 = param_1 << 8 | 1;
  uVar1 = r_ke_state_get(uVar2);
  iVar3 = *(int *)(&llc_env + param_1 * 4);
  if (1 < param_2) {
    r_assert_param(param_1,param_2,"llc.c",0x1d0);
  }
  piVar4 = (int *)(iVar3 + param_2 * 4);
  if (*piVar4 != 0) {
    r_assert_param(param_1,param_2,"llc.c",0x1d1);
  }
  iVar3 = r_sdk_config_get_opts_ext();
  if ((*(uint *)(iVar3 + 0x28) & 0x20) != 0) {
    iVar3 = r_sdk_config_get_opts_ext();
    if (*(byte *)(iVar3 + 0x2c) < 3) {
      r_ble_log_internal_x1
                (0x40a30025,
                 (uint)*(byte *)(param_3 + 5) << 0x18 | (uint)*(byte *)(param_3 + 4) << 0x10 |
                 param_2 << 8 | param_1);
    }
  }
  *piVar4 = param_3;
  if (uVar1 == 0xff) {
    r_assert_param(param_1,0xff,"llc.c",0x1d7);
  }
  r_ke_state_set(uVar2,(1 << (param_2 & 0x1f) | uVar1) & 0xff);
  return;
}

