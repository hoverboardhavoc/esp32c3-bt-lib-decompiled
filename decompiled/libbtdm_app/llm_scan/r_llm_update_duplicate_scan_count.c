/*
 * Last changed at upstream commit 5c6ab5248a124cffc731a9e4764473fdeef38054
 * https://github.com/espressif/esp32c3-bt-lib/commit/5c6ab5248a124cffc731a9e4764473fdeef38054
 * Upstream date: 2023-03-09 14:58:19 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(85a1090)
 * Source: libbtdm_app -> llm_scan.o -> r_llm_update_duplicate_scan_count
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llm_update_duplicate_scan_count(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  if (((*(char *)(_p_llm_env + 0xd7) != '\x02') &&
      (iVar1 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0)),
      *(short *)(iVar1 + 0x16) != 0)) && ((*(byte *)(_p_llm_env + 0xd4) & 1) != 0)) {
    iVar1 = (**(code **)(_r_ip_funcs_p + 0x924))(*(code **)(_r_ip_funcs_p + 0x924));
    uVar2 = *(uint *)(iVar1 + 0x18);
    uVar3 = *(int *)(iVar1 + 0x1c) + 1;
    *(uint *)(iVar1 + 0x1c) = uVar3;
    if (uVar2 <= uVar3) {
      *(undefined4 *)(iVar1 + 0x1c) = 0;
      *(undefined1 *)(iVar1 + 0x24) = 1;
    }
    if (*(char *)(iVar1 + 8) != '\0') {
      uVar3 = 1;
      uVar4 = *(int *)(iVar1 + 0x20) + 1;
      if (5 < uVar2) {
        uVar3 = uVar2 / 6;
      }
      if (uVar4 < uVar3) {
        *(uint *)(iVar1 + 0x20) = uVar4;
      }
      else {
        *(undefined4 *)(iVar1 + 0x20) = 0;
        *(undefined1 *)(iVar1 + 0x25) = 1;
      }
    }
  }
  return;
}

