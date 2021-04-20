/*
 * Last changed at upstream commit 352d001fc7f5d34243047454b3f9e684577ce3e0
 * https://github.com/espressif/esp32c3-bt-lib/commit/352d001fc7f5d34243047454b3f9e684577ce3e0
 * Upstream date: 2021-04-20 15:58:00 +0800
 * Upstream subject: ESP32C3, ESP32S3: update libbtdm_app.a(47235b66)
 * Source: libbtdm_app -> llm_adv.o -> hci_le_set_adv_set_rand_addr_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_set_adv_set_rand_addr_cmd_handler(undefined1 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = _r_ip_funcs_p;
  uVar1 = 0xc;
  if (*(char *)(_p_llm_env + 0xd7) != '\x01') {
    *(undefined1 *)(_p_llm_env + 0xd7) = 2;
    uVar1 = 0x42;
    uVar2 = (**(code **)(iVar3 + 0x544))(*param_1,0,*(code **)(iVar3 + 0x544));
    iVar3 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
    if (uVar2 < *(byte *)(iVar3 + 0xd)) {
      iVar3 = *(int *)(_p_llm_env + 8) + uVar2 * 0x44;
      memcpy((void *)(iVar3 + 4),param_1 + 1,6);
      uVar1 = 0;
      if (*(char *)(iVar3 + 0x40) == '\x02') {
        (**(code **)(_r_ip_funcs_p + 0x1d0))
                  (uVar2,*(undefined4 *)(param_1 + 1),*(undefined2 *)(param_1 + 5),
                   *(code **)(_r_ip_funcs_p + 0x1d0));
      }
    }
  }
  (**(code **)(_r_ip_funcs_p + 0x4b8))(param_2,uVar1,*(code **)(_r_ip_funcs_p + 0x4b8));
  return 0;
}

