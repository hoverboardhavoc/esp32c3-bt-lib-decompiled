/*
 * Last changed at upstream commit f23a340e82d6a4be40f83214385a98c5bd30ccdd
 * https://github.com/espressif/esp32c3-bt-lib/commit/f23a340e82d6a4be40f83214385a98c5bd30ccdd
 * Upstream date: 2025-04-03 18:07:15 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(a684dd5)
 * Source: libbtdm_app -> llm_adv.o -> llm_clear_adv
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 llm_clear_adv(void)

{
  uint uVar1;
  int iVar2;
  
  if (*(char *)(_p_llm_env + 0xd7) != '\x02') {
    *(undefined1 *)(_p_llm_env + 0xd7) = 1;
    uVar1 = (**(code **)(_r_ip_funcs_p + 0x544))(0xff,0,*(code **)(_r_ip_funcs_p + 0x544));
    iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
    if (*(byte *)(iVar2 + 0xd) <= uVar1) {
      return 0;
    }
    if (*(char *)(*(int *)(_p_llm_env + 8) + uVar1 * 0x44 + 0x40) == '\x01') {
      (**(code **)(_r_ip_funcs_p + 0x550))(uVar1,*(code **)(_r_ip_funcs_p + 0x550));
      return 0;
    }
  }
  return 0xc;
}

