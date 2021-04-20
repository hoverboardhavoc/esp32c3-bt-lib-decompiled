/*
 * Last changed at upstream commit 352d001fc7f5d34243047454b3f9e684577ce3e0
 * https://github.com/espressif/esp32c3-bt-lib/commit/352d001fc7f5d34243047454b3f9e684577ce3e0
 * Upstream date: 2021-04-20 15:58:00 +0800
 * Upstream subject: ESP32C3, ESP32S3: update libbtdm_app.a(47235b66)
 * Source: libbtdm_app -> llm_hci.o -> hci_le_set_host_ch_class_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_set_host_ch_class_cmd_handler(void *param_1,undefined4 param_2)

{
  char cVar1;
  undefined4 uVar2;
  
  uVar2 = 0xc;
  if (*(char *)(_p_llm_env + 0x23) == '\0') {
    if (((*(byte *)((int)param_1 + 4) & 0xe0) == 0) &&
       (cVar1 = (**(code **)(_r_modules_funcs_p + 0xc))(0xc,*(code **)(_r_modules_funcs_p + 0xc)),
       (byte)(cVar1 - 1U) < 0x25)) {
      memcpy((void *)(_p_llm_env + 0x18),param_1,5);
      (**(code **)(_r_modules_funcs_p + 0xc4))(5,0,100,*(code **)(_r_modules_funcs_p + 0xc4));
      *(undefined1 *)(_p_llm_env + 0x23) = 1;
      (**(code **)(_r_modules_funcs_p + 0xb8))(4,0,*(code **)(_r_modules_funcs_p + 0xb8));
      (**(code **)(_r_ip_funcs_p + 0x4b4))(*(code **)(_r_ip_funcs_p + 0x4b4));
      uVar2 = 0;
    }
    else {
      uVar2 = 0x12;
    }
  }
  (**(code **)(_r_ip_funcs_p + 0x4b8))(param_2,uVar2,*(code **)(_r_ip_funcs_p + 0x4b8));
  return 0;
}

