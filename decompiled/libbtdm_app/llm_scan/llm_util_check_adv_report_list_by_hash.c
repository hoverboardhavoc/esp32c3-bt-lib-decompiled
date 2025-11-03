/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app -> llm_scan.o -> llm_util_check_adv_report_list_by_hash
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 llm_util_check_adv_report_list_by_hash(int param_1)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  
  piVar1 = (int *)(**(code **)(_r_ip_funcs_p + 0x924))(*(code **)(_r_ip_funcs_p + 0x924));
  for (piVar5 = (int *)*piVar1; piVar5 != (int *)0x0; piVar5 = (int *)*piVar5) {
    if (piVar5[1] == param_1) {
      return 1;
    }
  }
  uVar2 = (**(code **)(_r_modules_funcs_p + 0x50))(piVar1,*(code **)(_r_modules_funcs_p + 0x50));
  if (uVar2 < *(ushort *)((int)piVar1 + 10)) {
    iVar3 = (**(code **)(_r_modules_funcs_p + 0x120))(8,3,*(code **)(_r_modules_funcs_p + 0x120));
    if (iVar3 == 0) {
      return 0;
    }
  }
  else {
    iVar3 = piVar1[1];
    if (iVar3 == 0) {
      return 0;
    }
    iVar4 = (**(code **)(_r_modules_funcs_p + 0x1c))
                      (piVar1,iVar3,*(code **)(_r_modules_funcs_p + 0x1c));
    if (iVar4 == 0) {
      (**(code **)(_r_plf_funcs_p + 8))("llm_scan.c",0x5f1,*(code **)(_r_plf_funcs_p + 8));
    }
  }
  iVar4 = _r_modules_funcs_p;
  *(int *)(iVar3 + 4) = param_1;
  (**(code **)(iVar4 + 0x4c))(piVar1,iVar3,*(code **)(iVar4 + 0x4c));
  return 0;
}

