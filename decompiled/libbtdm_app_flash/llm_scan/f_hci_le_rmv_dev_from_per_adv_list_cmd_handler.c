/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llm_scan.o -> f_hci_le_rmv_dev_from_per_adv_list_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 f_hci_le_rmv_dev_from_per_adv_list_cmd_handler(byte *param_1,undefined4 param_2)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  byte bVar4;
  uint uVar5;
  
  bVar4 = 0x12;
  if (param_1[7] < 0x10) {
    bVar4 = 0x12;
    if (*param_1 < 2) {
      if (*(char *)(_p_llm_env + 0xd7) != '\x01') {
        *(undefined1 *)(_p_llm_env + 0xd7) = 2;
        uVar2 = r_llm_activity_syncing_get(0x12);
        iVar3 = r_sdk_config_get_opts();
        if (*(byte *)(iVar3 + 0xd) <= uVar2) {
          uVar2 = r_llm_dev_list_search(param_1 + 1,*param_1);
          bVar4 = 0x42;
          if (uVar2 < 0xc) {
            iVar3 = _p_llm_env + uVar2 * 10;
            bVar4 = 0x42;
            if ((*(byte *)(iVar3 + 0x2d) & 4) != 0) {
              uVar5 = 1 << (param_1[7] & 0x1f);
              *(ushort *)(iVar3 + 0x2a) = *(ushort *)(iVar3 + 0x2a) & ~(ushort)uVar5;
              r_lld_per_adv_list_rem(param_1 + 1,*param_1,uVar5 & 0xffff);
              iVar3 = _p_llm_env + uVar2 * 10;
              if (*(short *)(iVar3 + 0x2a) == 0) {
                bVar1 = *(byte *)(iVar3 + 0x2d);
                bVar4 = bVar1 & 2;
                if ((bVar1 & 2) == 0) {
                  *(byte *)(iVar3 + 0x2d) = bVar1 & 0xfa;
                  goto _L327;
                }
                *(byte *)(iVar3 + 0x2d) = bVar1 & 0xfb;
              }
              bVar4 = 0;
            }
          }
          goto _L327;
        }
      }
      bVar4 = 0xc;
    }
  }
_L327:
  r_llm_cmd_cmp_send(param_2,bVar4);
  return 0;
}

