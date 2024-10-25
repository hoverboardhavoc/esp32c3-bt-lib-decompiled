/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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
      goto _L170;
    }
  }
  uVar4 = 0xc;
_L170:
  r_llm_cmd_cmp_send(param_1,uVar4);
  return 0;
}

