/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llm_adv.o -> hci_le_rmv_adv_set_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_rmv_adv_set_cmd_handler(undefined1 *param_1,undefined4 param_2)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined1 auStack_24 [8];
  
  iVar2 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar2 + 0x18) == '\0') {
    r_llm_cmd_cmp_send(param_2,0xc);
    return 0;
  }
  if (*(char *)(_p_llm_env + 0xd7) != '\x01') {
    *(undefined1 *)(_p_llm_env + 0xd7) = 2;
    iVar2 = r_llm_adv_hdl_to_id(*param_1,auStack_24);
    uVar3 = 0x42;
    if (iVar2 == 0xff) goto _L810;
    iVar4 = *(int *)(_p_llm_env + 8) + iVar2 * 0x44;
    if ((*(char *)(iVar4 + 0x40) == '\x01') &&
       ((bVar1 = *(byte *)(iVar4 + 0x3d), iVar4 = r_sdk_config_get_opts(0x42),
        *(byte *)(iVar4 + 0xd) <= bVar1 ||
        (*(char *)(*(int *)(_p_llm_env + 8) +
                   (uint)*(byte *)(iVar2 * 0x44 + *(int *)(_p_llm_env + 8) + 0x3d) * 0x44 + 0x40) ==
         '\n')))) {
      r_llm_adv_set_release_hack(iVar2);
      uVar3 = 0;
      goto _L810;
    }
  }
  uVar3 = 0xc;
_L810:
  r_llm_cmd_cmp_send(param_2,uVar3);
  return 0;
}

