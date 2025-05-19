/*
 * Last changed at upstream commit 72599d583c232ea78d6461b5b502426c6e5a1ec9
 * https://github.com/espressif/esp32c3-bt-lib/commit/72599d583c232ea78d6461b5b502426c6e5a1ec9
 * Upstream date: 2025-05-19 16:27:45 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(6cfabcd8)
 * Source: libbtdm_app -> llm_adv.o -> r_llm_adv_hdl_to_id
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint r_llm_adv_hdl_to_id(uint param_1,undefined4 *param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  byte *unaff_s2;
  
  for (uVar1 = 0; iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38)),
      uVar1 < *(byte *)(iVar2 + 0xd); uVar1 = uVar1 + 1 & 0xff) {
    puVar3 = (undefined4 *)(*(int *)(_p_llm_env + 8) + uVar1 * 0x44);
    if ((byte)(*(char *)(puVar3 + 0x10) - 1U) < 3) {
      unaff_s2 = (byte *)*puVar3;
      if (unaff_s2 == (byte *)0x0) {
        (**(code **)(_r_plf_funcs_p + 0xc))
                  (uVar1,"llm_adv.c",0xc91,*(code **)(_r_plf_funcs_p + 0xc));
      }
      if (*unaff_s2 == param_1) break;
    }
  }
  iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  if (uVar1 < *(byte *)(iVar2 + 0xd)) {
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = unaff_s2;
    }
  }
  else {
    uVar1 = 0xff;
  }
  return uVar1;
}

