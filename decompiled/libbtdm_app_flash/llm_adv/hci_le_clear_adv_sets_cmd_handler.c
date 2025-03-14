/*
 * Last changed at upstream commit e668c2d101ee46ee1950819607694fb852aecae0
 * https://github.com/espressif/esp32c3-bt-lib/commit/e668c2d101ee46ee1950819607694fb852aecae0
 * Upstream date: 2025-03-14 11:07:43 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(6e312587)
 * Source: libbtdm_app_flash -> llm_adv.o -> hci_le_clear_adv_sets_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_clear_adv_sets_cmd_handler(int param_1,undefined4 param_2)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar3 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar3 + 0x18) == '\0') {
    r_llm_cmd_cmp_send(param_2,0xc);
    return 0;
  }
  if (*(char *)(_p_llm_env + 0xd7) != '\x01') {
    *(undefined1 *)(_p_llm_env + 0xd7) = 2;
    uVar2 = 0;
    while (((param_1 = r_sdk_config_get_opts(param_1), uVar2 < *(byte *)(param_1 + 0xd) &&
            (cVar1 = *(char *)(*(int *)(_p_llm_env + 8) + uVar2 * 0x44 + 0x40),
            1 < (byte)(cVar1 - 2U))) && (1 < (byte)(cVar1 - 0xcU)))) {
      uVar2 = uVar2 + 1 & 0xff;
    }
    iVar3 = r_sdk_config_get_opts();
    if (*(byte *)(iVar3 + 0xd) <= uVar2) {
      for (uVar2 = 0; iVar3 = r_sdk_config_get_opts(), uVar2 < *(byte *)(iVar3 + 0xd);
          uVar2 = uVar2 + 1 & 0xff) {
        if (*(char *)(*(int *)(_p_llm_env + 8) + uVar2 * 0x44 + 0x40) == '\x01') {
          r_llm_adv_set_release_hack(uVar2);
        }
      }
      uVar4 = 0;
      goto _L170;
    }
  }
  uVar4 = 0xc;
_L170:
  r_llm_cmd_cmp_send(param_2,uVar4);
  return 0;
}

