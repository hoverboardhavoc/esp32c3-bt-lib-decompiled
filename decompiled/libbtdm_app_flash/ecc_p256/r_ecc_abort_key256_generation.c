/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> ecc_p256.o -> r_ecc_abort_key256_generation
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_ecc_abort_key256_generation(uint param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  
  piVar1 = (int *)_ecc_env;
  piVar3 = (int *)0;
  while( true ) {
    piVar2 = piVar1;
    if (piVar2 == (int *)0x0) {
      return;
    }
    if (*(ushort *)((int)piVar2 + 0x13e) == param_1) break;
    piVar1 = (int *)*piVar2;
    piVar3 = piVar2;
  }
  r_co_list_extract_after(&ecc_env,piVar3,piVar2);
  if (piVar2[0x52] != 0) {
    r_ke_free();
  }
  r_ke_free(piVar2);
  if (_ecc_env != 0) {
    return;
  }
  r_ke_event_clear(1);
  return;
}

