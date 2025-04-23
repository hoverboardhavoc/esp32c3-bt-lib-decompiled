/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llm_adv.o -> f_hci_le_set_adv_set_rand_addr_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 f_hci_le_set_adv_set_rand_addr_cmd_handler(undefined1 *param_1,undefined4 param_2)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  iVar3 = _r_ip_funcs_p;
  if (*(char *)(_p_llm_env + 0xd7) != '\x01') {
    *(undefined1 *)(_p_llm_env + 0xd7) = 2;
    uVar2 = (**(code **)(iVar3 + 0x544))(*param_1,0,*(code **)(iVar3 + 0x544));
    iVar5 = *(int *)(*(int *)(_p_llm_env + 8) + uVar2 * 0x44);
    iVar3 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
    uVar4 = 0x42;
    if (*(byte *)(iVar3 + 0xd) <= uVar2) goto _L176;
    iVar3 = *(int *)(_p_llm_env + 8) + uVar2 * 0x44;
    cVar1 = *(char *)(iVar3 + 0x40);
    if ((cVar1 != '\x02') || (*(short *)(iVar5 + 2) == 0)) {
      memcpy((void *)(iVar3 + 4),param_1 + 1,6);
      if (cVar1 == '\x02') {
        (**(code **)(_r_ip_funcs_p + 0x1d0))
                  (uVar2,*(undefined4 *)(param_1 + 1),*(undefined2 *)(param_1 + 5),
                   *(code **)(_r_ip_funcs_p + 0x1d0));
      }
      uVar4 = 0;
      goto _L176;
    }
  }
  uVar4 = 0xc;
_L176:
  (**(code **)(_r_ip_funcs_p + 0x4b8))(param_2,uVar4,*(code **)(_r_ip_funcs_p + 0x4b8));
  return 0;
}

