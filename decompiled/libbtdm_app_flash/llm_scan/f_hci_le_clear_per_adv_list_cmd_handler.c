/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> llm_scan.o -> f_hci_le_clear_per_adv_list_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 f_hci_le_clear_per_adv_list_cmd_handler(undefined4 param_1)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  
  if (*(char *)(_p_llm_env + 0xd7) != '\x01') {
    *(undefined1 *)(_p_llm_env + 0xd7) = 2;
    uVar3 = r_llm_activity_syncing_get();
    iVar4 = r_sdk_config_get_opts();
    if (*(byte *)(iVar4 + 0xd) <= uVar3) {
      uVar3 = 0;
      do {
        iVar4 = _p_llm_env;
        iVar6 = uVar3 * 10 + _p_llm_env;
        bVar1 = *(byte *)(iVar6 + 0x2d);
        if ((bVar1 & 1) != 0) {
          if ((bVar1 & 2) == 0) {
            bVar2 = 0xfa;
          }
          else {
            bVar2 = 0xfb;
          }
          *(byte *)(iVar6 + 0x2d) = bVar1 & bVar2;
          iVar6 = iVar4 + uVar3 * 10;
          *(undefined2 *)(iVar6 + 0x2a) = 0;
          r_lld_per_adv_list_rem
                    (uVar3 & 0xff,iVar4 + uVar3 * 10 + 0x24,*(undefined1 *)(iVar6 + 0x2c),0xffff);
        }
        uVar3 = uVar3 + 1;
      } while (uVar3 != 0xc);
      uVar5 = 0;
      goto _L345;
    }
  }
  uVar5 = 0xc;
_L345:
  r_llm_cmd_cmp_send(param_1,uVar5);
  return 0;
}

