/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llm.o -> r_llm_activity_free_get
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_llm_activity_free_get(byte *param_1)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  
  uVar5 = 0;
  do {
    *param_1 = (byte)uVar5;
    iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
    iVar4 = _p_llm_env;
    if (*(byte *)(iVar2 + 0xd) <= uVar5) {
_L383:
      bVar1 = *param_1;
      iVar4 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
      uVar3 = 7;
      if (bVar1 < *(byte *)(iVar4 + 0xd)) {
        uVar3 = 0;
      }
      return uVar3;
    }
    iVar2 = *(int *)(_p_llm_env + 8) + (uint)*param_1 * 0x44;
    if (*(char *)(iVar2 + 0x40) == '\0') {
      memset((void *)(iVar2 + 0x28),0,0x18);
      iVar4 = *(int *)(iVar4 + 8);
      *(undefined2 *)((uint)*param_1 * 0x44 + iVar4 + 0x30) = 0x672;
      *(undefined2 *)((uint)*param_1 * 0x44 + iVar4 + 0x3a) = 0x672;
      *(undefined2 *)(iVar4 + (uint)*param_1 * 0x44 + 0x30) = 0x672;
      uVar5 = (uint)*param_1;
      *(undefined4 *)((uVar5 + 0x1800c4cb) * 4) = 0;
      (**(code **)(_r_modules_funcs_p + 0x1d8))(uVar5,*(code **)(_r_modules_funcs_p + 0x1d8));
      (**(code **)(_r_modules_funcs_p + 0x200))(uVar5,*(code **)(_r_modules_funcs_p + 0x200));
      goto _L383;
    }
    uVar5 = *param_1 + 1 & 0xff;
  } while( true );
}

