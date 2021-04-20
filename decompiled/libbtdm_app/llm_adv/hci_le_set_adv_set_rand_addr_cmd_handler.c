/*
 * Last changed at upstream commit 022b7da7fcf0043f891c2e8ccd8c241243018e2f
 * https://github.com/espressif/esp32c3-bt-lib/commit/022b7da7fcf0043f891c2e8ccd8c241243018e2f
 * Upstream date: 2021-04-20 16:00:04 +0800
 * Upstream subject: ESP32-C3, ESP32-S3: update libbtdm_app.a(d1d0c6f1)
 * Source: libbtdm_app -> llm_adv.o -> hci_le_set_adv_set_rand_addr_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_set_adv_set_rand_addr_cmd_handler(undefined1 *param_1,undefined4 param_2)

{
  char cVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = _r_ip_funcs_p;
  if (*(char *)(_p_llm_env + 0xd7) != '\x01') {
    *(undefined1 *)(_p_llm_env + 0xd7) = 2;
    uVar2 = 0x42;
    uVar3 = (**(code **)(iVar4 + 0x544))(*param_1,0,*(code **)(iVar4 + 0x544));
    iVar5 = *(int *)(*(int *)(_p_llm_env + 8) + uVar3 * 0x44);
    iVar4 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
    if (((*(byte *)(iVar4 + 0xd) <= uVar3) || (uVar2 = 0x12, iVar5 == 0)) ||
       ((*(byte *)(iVar5 + 0xb) & 1) == 0)) goto _L171;
    iVar4 = *(int *)(_p_llm_env + 8) + uVar3 * 0x44;
    cVar1 = *(char *)(iVar4 + 0x40);
    if ((cVar1 != '\x02') || (*(short *)(iVar5 + 2) == 0)) {
      memcpy((void *)(iVar4 + 4),param_1 + 1,6);
      uVar2 = 0;
      if (cVar1 == '\x02') {
        (**(code **)(_r_ip_funcs_p + 0x1d0))
                  (uVar3,*(undefined4 *)(param_1 + 1),*(undefined2 *)(param_1 + 5),
                   *(code **)(_r_ip_funcs_p + 0x1d0));
      }
      goto _L171;
    }
  }
  uVar2 = 0xc;
_L171:
  (**(code **)(_r_ip_funcs_p + 0x4b8))(param_2,uVar2,*(code **)(_r_ip_funcs_p + 0x4b8));
  return 0;
}

