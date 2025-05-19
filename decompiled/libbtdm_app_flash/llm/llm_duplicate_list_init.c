/*
 * Last changed at upstream commit 72599d583c232ea78d6461b5b502426c6e5a1ec9
 * https://github.com/espressif/esp32c3-bt-lib/commit/72599d583c232ea78d6461b5b502426c6e5a1ec9
 * Upstream date: 2025-05-19 16:27:45 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(6cfabcd8)
 * Source: libbtdm_app_flash -> llm.o -> llm_duplicate_list_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void llm_duplicate_list_init(void)

{
  undefined2 uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar2 = p_le_scan_duplicate_option;
  uVar3 = sdk_config_get_mask();
  if ((uVar3 & 1) != 0) {
    iVar4 = r_co_list_size(iVar2 + 0x10);
    if (iVar4 != 0) {
      llm_util_flush_list(iVar2 + 0x10);
    }
    iVar4 = r_co_list_size(iVar2);
    if (iVar4 != 0) {
      llm_util_flush_list(iVar2);
    }
    iVar4 = r_sdk_config_get_opts_ext();
    *(bool *)(iVar2 + 8) = *(char *)(iVar4 + 4) == '\x01';
    iVar4 = r_sdk_config_get_opts_ext();
    *(undefined1 *)(iVar2 + 9) = *(undefined1 *)(iVar4 + 5);
    iVar4 = r_sdk_config_get_opts_ext();
    *(undefined2 *)(iVar2 + 10) = *(undefined2 *)(iVar4 + 6);
    iVar4 = r_sdk_config_get_opts_ext();
    uVar1 = *(undefined2 *)(iVar4 + 8);
    *(undefined4 *)(iVar2 + 0x18) = 0;
    *(undefined4 *)(iVar2 + 0x1c) = 0;
    *(undefined2 *)(iVar2 + 0xc) = uVar1;
  }
  if (*(char *)(iVar2 + 8) != '\0') {
    r_co_list_init(iVar2 + 0x10);
  }
  r_co_list_init(iVar2);
  return;
}

