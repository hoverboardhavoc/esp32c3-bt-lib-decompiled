/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llm_scan.o -> f_hci_le_add_dev_to_per_adv_list_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 f_hci_le_add_dev_to_per_adv_list_cmd_handler(byte *param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  byte *__src;
  
  iVar2 = _r_ip_funcs_p;
  if ((param_1[7] < 0x10) && (*param_1 < 2)) {
    if (*(char *)(_p_llm_env + 0xd7) != '\x01') {
      *(undefined1 *)(_p_llm_env + 0xd7) = 2;
      uVar1 = (**(code **)(iVar2 + 0x510))(*(code **)(iVar2 + 0x510));
      iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
      if (*(byte *)(iVar2 + 0xd) <= uVar1) {
        __src = param_1 + 1;
        uVar1 = (**(code **)(_r_ip_funcs_p + 0x4c8))
                          (__src,*param_1,*(code **)(_r_ip_funcs_p + 0x4c8));
        if (uVar1 < 0xc) {
          iVar2 = _p_llm_env + uVar1 * 10;
          if (((*(byte *)(iVar2 + 0x2d) & 4) != 0) &&
             (((int)(uint)*(ushort *)(iVar2 + 0x2a) >> (param_1[7] & 0x1f) & 1U) != 0)) goto _L238;
        }
        else {
          uVar3 = 7;
          uVar1 = (**(code **)(_r_ip_funcs_p + 0x4c4))(*(code **)(_r_ip_funcs_p + 0x4c4));
          if (uVar1 == 0xc) goto _L237;
        }
        memcpy((void *)(_p_llm_env + uVar1 * 10 + 0x24),__src,6);
        iVar2 = _p_llm_env + uVar1 * 10;
        *(byte *)(iVar2 + 0x2c) = *param_1;
        *(ushort *)(iVar2 + 0x2a) = *(ushort *)(iVar2 + 0x2a) | (ushort)(1 << (param_1[7] & 0x1f));
        uVar3 = 0;
        *(byte *)(iVar2 + 0x2d) = *(byte *)(iVar2 + 0x2d) | 5;
        iVar2 = (**(code **)(_r_ip_funcs_p + 0x4dc))(__src,*(code **)(_r_ip_funcs_p + 0x4dc));
        if (iVar2 == 0) {
          (**(code **)(_r_ip_funcs_p + 600))
                    (uVar1,__src,*param_1,param_1[7],*(code **)(_r_ip_funcs_p + 600));
        }
        goto _L237;
      }
    }
    uVar3 = 0xc;
  }
  else {
_L238:
    uVar3 = 0x12;
  }
_L237:
  (**(code **)(_r_ip_funcs_p + 0x4b8))(param_2,uVar3,*(code **)(_r_ip_funcs_p + 0x4b8));
  return 0;
}

