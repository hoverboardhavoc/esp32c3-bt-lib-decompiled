/*
 * Last changed at upstream commit 022b7da7fcf0043f891c2e8ccd8c241243018e2f
 * https://github.com/espressif/esp32c3-bt-lib/commit/022b7da7fcf0043f891c2e8ccd8c241243018e2f
 * Upstream date: 2021-04-20 16:00:04 +0800
 * Upstream subject: ESP32-C3, ESP32-S3: update libbtdm_app.a(d1d0c6f1)
 * Source: libbtdm_app -> llm_adv.o -> hci_le_rmv_adv_set_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_rmv_adv_set_cmd_handler(undefined1 *param_1,undefined4 param_2)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined1 auStack_24 [4];
  
  iVar2 = _r_ip_funcs_p;
  if (*(char *)(_p_llm_env + 0xd7) != '\x01') {
    *(undefined1 *)(_p_llm_env + 0xd7) = 2;
    iVar2 = (**(code **)(iVar2 + 0x544))(*param_1,auStack_24,*(code **)(iVar2 + 0x544));
    uVar3 = 0x42;
    if (iVar2 == 0xff) goto _L552;
    iVar4 = *(int *)(_p_llm_env + 8) + iVar2 * 0x44;
    if ((*(char *)(iVar4 + 0x40) == '\x01') &&
       ((bVar1 = *(byte *)(iVar4 + 0x3d),
        iVar4 = (**(code **)(_r_plf_funcs_p + 0x38))(0x42,*(code **)(_r_plf_funcs_p + 0x38)),
        *(byte *)(iVar4 + 0xd) <= bVar1 ||
        (*(char *)(*(int *)(_p_llm_env + 8) +
                   (uint)*(byte *)(iVar2 * 0x44 + *(int *)(_p_llm_env + 8) + 0x3d) * 0x44 + 0x40) ==
         '\n')))) {
      (**(code **)(_r_ip_funcs_p + 0x550))(iVar2,*(code **)(_r_ip_funcs_p + 0x550));
      uVar3 = 0;
      goto _L552;
    }
  }
  uVar3 = 0xc;
_L552:
  (**(code **)(_r_ip_funcs_p + 0x4b8))(param_2,uVar3,*(code **)(_r_ip_funcs_p + 0x4b8));
  return 0;
}

