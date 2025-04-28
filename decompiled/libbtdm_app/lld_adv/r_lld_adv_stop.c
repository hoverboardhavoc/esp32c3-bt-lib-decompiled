/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld_adv.o -> r_lld_adv_stop
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 r_lld_adv_stop(int param_1)

{
  byte bVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  iVar4 = *(int *)(&lld_adv_env + param_1 * 4);
  uVar2 = 0xc;
  if (iVar4 != 0) {
    if (*(char *)(iVar4 + 0x89) == '\0') {
      (**(code **)(_r_ip_funcs_p + 0x1a0))(1,0,*(code **)(_r_ip_funcs_p + 0x1a0));
      uVar2 = 0;
    }
    else {
      if (*(char *)(iVar4 + 0x89) == '\x01') {
        bVar1 = *(byte *)(iVar4 + 0x87);
        iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
        *(undefined2 *)((uint)bVar1 * 0x5a + 0x20 + iVar3) = 1;
        _DAT_60031000 = _DAT_60031000 & 0xfdffffff | 0x2000000;
        *(undefined1 *)(iVar4 + 0x89) = 2;
      }
      uVar2 = 0;
    }
  }
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return uVar2;
}

