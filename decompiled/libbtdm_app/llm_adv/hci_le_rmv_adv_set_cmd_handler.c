/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app -> llm_adv.o -> hci_le_rmv_adv_set_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_rmv_adv_set_cmd_handler(undefined1 *param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined1 auStack_24 [8];
  
  iVar3 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
  iVar2 = _r_ip_funcs_p;
  if (*(char *)(iVar3 + 0x18) == '\0') {
    (**(code **)(_r_ip_funcs_p + 0x4b8))(param_2,0xc,*(code **)(_r_ip_funcs_p + 0x4b8));
    return 0;
  }
  if (*(char *)(_p_llm_env + 0xd7) != '\x01') {
    *(undefined1 *)(_p_llm_env + 0xd7) = 2;
    iVar2 = (**(code **)(iVar2 + 0x544))(*param_1,auStack_24,*(code **)(iVar2 + 0x544));
    uVar4 = 0x42;
    if (iVar2 == 0xff) goto _L640;
    iVar3 = *(int *)(_p_llm_env + 8) + iVar2 * 0x44;
    if (*(char *)(iVar3 + 0x40) == '\x01') {
      uVar1 = (uint)*(byte *)(iVar3 + 0x3d);
      iVar3 = (**(code **)(_r_plf_funcs_p + 0x38))(0x42,*(code **)(_r_plf_funcs_p + 0x38));
      if ((*(byte *)(iVar3 + 0xd) <= uVar1) ||
         (*(char *)(*(int *)(_p_llm_env + 8) + uVar1 * 0x44 + 0x40) == '\n')) {
        (**(code **)(_r_ip_funcs_p + 0x550))(iVar2,*(code **)(_r_ip_funcs_p + 0x550));
        uVar4 = 0;
        goto _L640;
      }
    }
  }
  uVar4 = 0xc;
_L640:
  (**(code **)(_r_ip_funcs_p + 0x4b8))(param_2,uVar4,*(code **)(_r_ip_funcs_p + 0x4b8));
  return 0;
}

