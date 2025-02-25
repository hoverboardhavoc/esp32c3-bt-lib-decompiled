/*
 * Last changed at upstream commit 2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * https://github.com/espressif/esp32c3-bt-lib/commit/2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * Upstream date: 2025-02-25 15:16:47 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(723439d)
 * Source: libbtdm_app_flash -> llm_adv.o -> f_hci_le_clear_adv_sets_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 f_hci_le_clear_adv_sets_cmd_handler(undefined4 param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  
  if (*(char *)(_p_llm_env + 0xd7) != '\x01') {
    *(undefined1 *)(_p_llm_env + 0xd7) = 2;
    uVar2 = 0;
    while( true ) {
      iVar3 = r_sdk_config_get_opts();
      if (*(byte *)(iVar3 + 0xd) <= uVar2) break;
      cVar1 = *(char *)(*(int *)(_p_llm_env + 8) + uVar2 * 0x44 + 0x40);
      if (((byte)(cVar1 - 2U) < 2) || ((byte)(cVar1 - 0xcU) < 2)) break;
      uVar2 = uVar2 + 1 & 0xff;
    }
    iVar3 = r_sdk_config_get_opts();
    if (*(byte *)(iVar3 + 0xd) <= uVar2) {
      uVar2 = 0;
      while( true ) {
        iVar3 = r_sdk_config_get_opts();
        if (*(byte *)(iVar3 + 0xd) <= uVar2) break;
        if (*(char *)(*(int *)(_p_llm_env + 8) + uVar2 * 0x44 + 0x40) == '\x01') {
          r_llm_adv_set_release_hack(uVar2);
        }
        uVar2 = uVar2 + 1 & 0xff;
      }
      uVar4 = 0;
      goto _L182;
    }
  }
  uVar4 = 0xc;
_L182:
  r_llm_cmd_cmp_send(param_1,uVar4);
  return 0;
}

