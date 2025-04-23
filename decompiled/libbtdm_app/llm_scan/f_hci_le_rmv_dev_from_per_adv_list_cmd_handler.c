/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llm_scan.o -> f_hci_le_rmv_dev_from_per_adv_list_cmd_handler
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
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  
  iVar3 = _r_ip_funcs_p;
  uVar4 = 0x12;
  if ((param_1[7] < 0x10) && (uVar4 = 0x12, *param_1 < 2)) {
    if (*(char *)(_p_llm_env + 0xd7) != '\x01') {
      *(undefined1 *)(_p_llm_env + 0xd7) = 2;
      uVar2 = (**(code **)(iVar3 + 0x510))(0x12,*(code **)(iVar3 + 0x510));
      iVar3 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
      if (*(byte *)(iVar3 + 0xd) <= uVar2) {
        uVar2 = (**(code **)(_r_ip_funcs_p + 0x4c8))
                          (param_1 + 1,*param_1,*(code **)(_r_ip_funcs_p + 0x4c8));
        iVar3 = _r_ip_funcs_p;
        uVar4 = 0x42;
        if (uVar2 < 0xc) {
          iVar6 = _p_llm_env + uVar2 * 10;
          uVar4 = 0x42;
          if ((*(byte *)(iVar6 + 0x2d) & 4) != 0) {
            uVar5 = 1 << (param_1[7] & 0x1f);
            *(ushort *)(iVar6 + 0x2a) = *(ushort *)(iVar6 + 0x2a) & ~(ushort)uVar5;
            (**(code **)(iVar3 + 0x25c))
                      (param_1 + 1,*param_1,uVar5 & 0xffff,*(code **)(iVar3 + 0x25c));
            iVar3 = _p_llm_env + uVar2 * 10;
            if (*(short *)(iVar3 + 0x2a) == 0) {
              if ((*(byte *)(iVar3 + 0x2d) & 2) == 0) {
                bVar1 = 0xfa;
              }
              else {
                bVar1 = 0xfb;
              }
              *(byte *)(iVar3 + 0x2d) = *(byte *)(iVar3 + 0x2d) & bVar1;
            }
            uVar4 = 0;
          }
        }
        goto _L243;
      }
    }
    uVar4 = 0xc;
  }
_L243:
  (**(code **)(_r_ip_funcs_p + 0x4b8))(param_2,uVar4,*(code **)(_r_ip_funcs_p + 0x4b8));
  return 0;
}

