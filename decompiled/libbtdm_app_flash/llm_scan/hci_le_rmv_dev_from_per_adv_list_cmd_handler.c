/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llm_scan.o -> hci_le_rmv_dev_from_per_adv_list_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_rmv_dev_from_per_adv_list_cmd_handler(byte *param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  byte bVar5;
  
  iVar2 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar2 + 0x18) == '\0') {
    r_llm_cmd_cmp_send(param_2,0xc);
    return 0;
  }
  uVar3 = 0x12;
  if ((param_1[7] < 0x10) && (uVar3 = 0x12, *param_1 < 2)) {
    if (*(char *)(_p_llm_env + 0xd7) != '\x01') {
      *(undefined1 *)(_p_llm_env + 0xd7) = 2;
      uVar1 = r_llm_activity_syncing_get(0x12);
      iVar2 = r_sdk_config_get_opts();
      if (*(byte *)(iVar2 + 0xd) <= uVar1) {
        uVar1 = r_llm_dev_list_search(param_1 + 1,*param_1);
        uVar3 = 0x42;
        if (uVar1 < 0xc) {
          iVar2 = _p_llm_env + uVar1 * 10;
          uVar3 = 0x42;
          if ((*(byte *)(iVar2 + 0x2d) & 4) != 0) {
            uVar4 = 1 << (param_1[7] & 0x1f);
            *(ushort *)(iVar2 + 0x2a) = ~(ushort)uVar4 & *(ushort *)(iVar2 + 0x2a);
            r_lld_per_adv_list_rem(param_1 + 1,*param_1,uVar4 & 0xffff);
            iVar2 = _p_llm_env + uVar1 * 10;
            if (*(short *)(iVar2 + 0x2a) == 0) {
              bVar5 = *(byte *)(iVar2 + 0x2d);
              if ((bVar5 & 2) == 0) {
                bVar5 = bVar5 & 0xfa;
              }
              else {
                bVar5 = bVar5 & 0xfb;
              }
              *(byte *)(iVar2 + 0x2d) = bVar5;
            }
            uVar3 = 0;
          }
        }
        goto _L318;
      }
    }
    uVar3 = 0xc;
  }
_L318:
  r_llm_cmd_cmp_send(param_2,uVar3);
  return 0;
}

