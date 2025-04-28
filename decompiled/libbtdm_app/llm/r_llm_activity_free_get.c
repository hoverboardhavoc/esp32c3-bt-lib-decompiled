/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
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
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  uVar2 = 0;
  do {
    *param_1 = (byte)uVar2;
    iVar3 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
    iVar5 = _p_llm_env;
    if (*(byte *)(iVar3 + 0xd) <= uVar2) {
_L409:
      bVar1 = *param_1;
      iVar5 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
      uVar4 = 0;
      if (*(byte *)(iVar5 + 0xd) <= bVar1) {
        uVar4 = 7;
      }
      return uVar4;
    }
    iVar3 = *(int *)(_p_llm_env + 8) + (uint)*param_1 * 0x44;
    if (*(char *)(iVar3 + 0x40) == '\0') {
      memset((void *)(iVar3 + 0x28),0,0x18);
      iVar5 = *(int *)(iVar5 + 8);
      *(undefined2 *)((uint)*param_1 * 0x44 + iVar5 + 0x30) = 0x672;
      *(undefined2 *)((uint)*param_1 * 0x44 + iVar5 + 0x3a) = 0x672;
      *(undefined2 *)(iVar5 + (uint)*param_1 * 0x44 + 0x30) = 0x672;
      uVar2 = (uint)*param_1;
      *(undefined4 *)((uVar2 + 0x1800c4cb) * 4) = 0;
      (**(code **)(_r_modules_funcs_p + 0x1d8))(uVar2,*(code **)(_r_modules_funcs_p + 0x1d8));
      (**(code **)(_r_modules_funcs_p + 0x200))(uVar2,*(code **)(_r_modules_funcs_p + 0x200));
      goto _L409;
    }
    uVar2 = *param_1 + 1 & 0xff;
  } while( true );
}

