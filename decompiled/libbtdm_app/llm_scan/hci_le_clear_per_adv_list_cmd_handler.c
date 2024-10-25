/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> llm_scan.o -> hci_le_clear_per_adv_list_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_clear_per_adv_list_cmd_handler(undefined4 param_1,undefined4 param_2)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  code *pcVar7;
  
  iVar5 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
  iVar4 = _r_ip_funcs_p;
  if (*(char *)(iVar5 + 0x18) == '\0') {
    (**(code **)(_r_ip_funcs_p + 0x4b8))(param_2,0xc,*(code **)(_r_ip_funcs_p + 0x4b8));
    return 0;
  }
  if (*(char *)(_p_llm_env + 0xd7) != '\x01') {
    *(undefined1 *)(_p_llm_env + 0xd7) = 2;
    uVar3 = (**(code **)(iVar4 + 0x510))(param_1,*(code **)(iVar4 + 0x510));
    iVar4 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
    if (*(byte *)(iVar4 + 0xd) <= uVar3) {
      uVar3 = 0;
      do {
        iVar4 = _p_llm_env;
        iVar5 = uVar3 * 10 + _p_llm_env;
        bVar1 = *(byte *)(iVar5 + 0x2d);
        if ((bVar1 & 1) != 0) {
          if ((bVar1 & 2) == 0) {
            bVar2 = 0xfa;
          }
          else {
            bVar2 = 0xfb;
          }
          *(byte *)(iVar5 + 0x2d) = bVar1 & bVar2;
          pcVar7 = *(code **)(_r_ip_funcs_p + 0x25c);
          iVar5 = iVar4 + uVar3 * 10;
          *(undefined2 *)(iVar5 + 0x2a) = 0;
          (*pcVar7)(uVar3 & 0xff,iVar4 + uVar3 * 10 + 0x24,*(undefined1 *)(iVar5 + 0x2c),0xffff,
                    pcVar7);
        }
        uVar3 = uVar3 + 1;
      } while (uVar3 != 0xc);
      uVar6 = 0;
      goto _L285;
    }
  }
  uVar6 = 0xc;
_L285:
  (**(code **)(_r_ip_funcs_p + 0x4b8))(param_2,uVar6,*(code **)(_r_ip_funcs_p + 0x4b8));
  return 0;
}

