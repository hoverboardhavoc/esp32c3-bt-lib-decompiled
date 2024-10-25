/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> llm.o -> r_llm_dev_list_empty_entry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llm_dev_list_empty_entry(void)

{
  char cVar1;
  byte *pbVar2;
  
  cVar1 = '\0';
  pbVar2 = (byte *)(_p_llm_env + 0x2d);
  do {
    if ((*pbVar2 & 1) == 0) {
      return;
    }
    cVar1 = cVar1 + '\x01';
    pbVar2 = pbVar2 + 10;
  } while (cVar1 != '\f');
  return;
}

