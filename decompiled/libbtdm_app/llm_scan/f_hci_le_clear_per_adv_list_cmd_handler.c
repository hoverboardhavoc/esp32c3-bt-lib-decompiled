/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> llm_scan.o -> f_hci_le_clear_per_adv_list_cmd_handler
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
      goto _L285;
    }
  }
  uVar5 = 0xc;
_L285:
  (**(code **)(_r_ip_funcs_p + 0x4b8))(param_1,uVar5,*(code **)(_r_ip_funcs_p + 0x4b8));
  return 0;
}

