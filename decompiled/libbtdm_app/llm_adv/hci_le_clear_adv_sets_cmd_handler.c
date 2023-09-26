/*
 * Last changed at upstream commit 27af69ccbb02f3b820436f47eaa0b1cd544edfbc
 * https://github.com/espressif/esp32c3-bt-lib/commit/27af69ccbb02f3b820436f47eaa0b1cd544edfbc
 * Upstream date: 2023-09-26 16:09:19 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(c8aa206)
 * Source: libbtdm_app -> llm_adv.o -> hci_le_clear_adv_sets_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_clear_adv_sets_cmd_handler(undefined4 param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  
  if (*(char *)(_p_llm_env + 0xd7) != '\x01') {
    *(undefined1 *)(_p_llm_env + 0xd7) = 2;
    for (uVar2 = 0; iVar3 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38)),
        uVar2 < *(byte *)(iVar3 + 0xd); uVar2 = uVar2 + 1 & 0xff) {
      cVar1 = *(char *)(*(int *)(_p_llm_env + 8) + uVar2 * 0x44 + 0x40);
      if (((byte)(cVar1 - 2U) < 2) || ((byte)(cVar1 - 0xcU) < 2)) break;
    }
    iVar3 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
    if (*(byte *)(iVar3 + 0xd) <= uVar2) {
      for (uVar2 = 0;
          iVar3 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38)),
          uVar2 < *(byte *)(iVar3 + 0xd); uVar2 = uVar2 + 1 & 0xff) {
        if (*(char *)(*(int *)(_p_llm_env + 8) + uVar2 * 0x44 + 0x40) == '\x01') {
          (**(code **)(_r_ip_funcs_p + 0x550))(uVar2,*(code **)(_r_ip_funcs_p + 0x550));
        }
      }
      uVar4 = 0;
      goto _L550;
    }
  }
  uVar4 = 0xc;
_L550:
  (**(code **)(_r_ip_funcs_p + 0x4b8))(param_1,uVar4,*(code **)(_r_ip_funcs_p + 0x4b8));
  return 0;
}

