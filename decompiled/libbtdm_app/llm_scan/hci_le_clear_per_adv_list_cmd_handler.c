/*
 * Last changed at upstream commit 5c6ab5248a124cffc731a9e4764473fdeef38054
 * https://github.com/espressif/esp32c3-bt-lib/commit/5c6ab5248a124cffc731a9e4764473fdeef38054
 * Upstream date: 2023-03-09 14:58:19 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(85a1090)
 * Source: libbtdm_app -> llm_scan.o -> hci_le_clear_per_adv_list_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_clear_per_adv_list_cmd_handler(undefined4 param_1)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  code *pcVar7;
  
  iVar4 = _r_ip_funcs_p;
  if (*(char *)(_p_llm_env + 0xd7) != '\x01') {
    *(undefined1 *)(_p_llm_env + 0xd7) = 2;
    uVar3 = (**(code **)(iVar4 + 0x510))(*(code **)(iVar4 + 0x510));
    iVar4 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
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
          pcVar7 = *(code **)(_r_ip_funcs_p + 0x25c);
          iVar6 = iVar4 + uVar3 * 10;
          *(undefined2 *)(iVar6 + 0x2a) = 0;
          (*pcVar7)(uVar3 & 0xff,iVar4 + uVar3 * 10 + 0x24,*(undefined1 *)(iVar6 + 0x2c),0xffff,
                    pcVar7);
        }
        uVar3 = uVar3 + 1;
      } while (uVar3 != 0xc);
      uVar5 = 0;
      goto _L231;
    }
  }
  uVar5 = 0xc;
_L231:
  (**(code **)(_r_ip_funcs_p + 0x4b8))(param_1,uVar5,*(code **)(_r_ip_funcs_p + 0x4b8));
  return 0;
}

