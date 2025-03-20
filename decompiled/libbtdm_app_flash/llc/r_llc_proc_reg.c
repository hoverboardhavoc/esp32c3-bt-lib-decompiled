/*
 * Last changed at upstream commit aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * https://github.com/espressif/esp32c3-bt-lib/commit/aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * Upstream date: 2025-03-20 20:31:24 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(d74042a8)
 * Source: libbtdm_app_flash -> llc.o -> r_llc_proc_reg
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_llc_proc_reg(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  
  uVar2 = param_1 << 8 | 1;
  uVar1 = r_ke_state_get(uVar2);
  iVar3 = *(int *)(&llc_env + param_1 * 4);
  if (1 < param_2) {
    r_assert_param(param_1,param_2,"llc.c",0x1cc);
  }
  piVar4 = (int *)(iVar3 + param_2 * 4);
  if (*piVar4 != 0) {
    r_assert_param(param_1,param_2,"llc.c",0x1cd);
  }
  *piVar4 = param_3;
  if (uVar1 == 0xff) {
    r_assert_param(param_1,0xff,"llc.c",0x1d2);
  }
  r_ke_state_set(uVar2,(1 << (param_2 & 0x1f) | uVar1) & 0xff);
  return;
}

