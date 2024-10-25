/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llm_scan.o -> r_llm_scan_start
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llm_scan_start(int param_1,undefined1 param_2)

{
  bool bVar1;
  int iVar2;
  undefined4 *puVar3;
  char *pcVar4;
  uint uVar5;
  undefined4 uStack_28;
  undefined2 uStack_24;
  undefined1 uStack_22;
  byte bStack_21;
  ushort uStack_20;
  ushort uStack_1e;
  ushort uStack_1c;
  ushort uStack_1a;
  char cStack_18;
  char cStack_17;
  char cStack_16;
  char cStack_15;
  undefined1 uStack_14;
  undefined2 uStack_12;
  
  puVar3 = (undefined4 *)(*(int *)(_p_llm_env + 8) + param_1 * 0x44);
  pcVar4 = (char *)*puVar3;
  bStack_21 = pcVar4[2];
  uStack_1c = 0;
  bVar1 = (bStack_21 & 1) != 0;
  if (bVar1) {
    cStack_18 = pcVar4[4];
    uStack_20 = *(ushort *)(pcVar4 + 6);
    uStack_1c = *(ushort *)(pcVar4 + 8);
  }
  uStack_1a = 0;
  if ((bStack_21 & 4) != 0) {
    cStack_17 = pcVar4[(uint)bVar1 * 6 + 4];
    uStack_1e = *(ushort *)(pcVar4 + (uint)bVar1 * 6 + 6);
    uStack_1a = *(ushort *)(pcVar4 + (uint)bVar1 * 6 + 8);
  }
  if (bStack_21 == 5) {
    uVar5 = (uint)uStack_1c + (uint)uStack_1a;
    if (uStack_20 < uVar5) {
      uStack_20 = (ushort)uVar5;
    }
    if (uStack_1e < uVar5) {
      uStack_1e = (ushort)uVar5;
    }
  }
  cStack_16 = *pcVar4;
  cStack_15 = pcVar4[1];
  uStack_12 = *(undefined2 *)(puVar3 + 10);
  uStack_14 = *(undefined1 *)(_p_llm_env + 0xc6);
  uStack_22 = param_2;
  if (cStack_16 != '\x01') {
    if ((cStack_16 == '\0') || (cStack_16 == '\x02')) {
      uStack_28 = *(undefined4 *)(_p_llm_env + 0xc);
      uStack_24 = *(undefined2 *)(_p_llm_env + 0x10);
      goto _L367;
    }
    if (cStack_16 != '\x03') {
      r_assert_param(0,"llm_scan.c",0x8c2);
      goto _L367;
    }
  }
  memcpy(&uStack_28,(void *)(_p_llm_env + 0x12),6);
_L367:
  iVar2 = r_lld_scan_start_eco(param_1,&uStack_28);
  if (iVar2 != 0) {
    r_assert_err(0,"llm_scan.c",0x8ca);
  }
  return;
}

