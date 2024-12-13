/*
 * Last changed at upstream commit c57c0b11c3c0065a16b66685715100a189ef9b27
 * https://github.com/espressif/esp32c3-bt-lib/commit/c57c0b11c3c0065a16b66685715100a189ef9b27
 * Upstream date: 2024-12-13 13:39:25 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(555b0a2)
 * Source: libbtdm_app_flash -> llm_scan.o -> r_llm_scan_start_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llm_scan_start_eco(int param_1,undefined4 param_2)

{
  bool bVar1;
  int iVar2;
  char *pcVar3;
  undefined4 *puVar4;
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
  undefined4 uStack_14;
  
  uStack_14 = param_2;
  pcVar3 = (char *)r_ble_ll_qa_config_get();
  if (*pcVar3 != '\0') {
    pcVar3[8] = '\0';
    pcVar3[9] = '\0';
    pcVar3[10] = '\0';
    pcVar3[0xb] = '\0';
  }
  puVar4 = (undefined4 *)(*(int *)(_p_llm_env + 8) + param_1 * 0x44);
  pcVar3 = (char *)*puVar4;
  bStack_21 = pcVar3[2];
  uStack_1c = 0;
  bVar1 = (bStack_21 & 1) != 0;
  if (bVar1) {
    cStack_18 = pcVar3[4];
    uStack_20 = *(ushort *)(pcVar3 + 6);
    uStack_1c = *(ushort *)(pcVar3 + 8);
  }
  uStack_1a = 0;
  if ((bStack_21 & 4) != 0) {
    cStack_17 = pcVar3[(uint)bVar1 * 6 + 4];
    uStack_1e = *(ushort *)(pcVar3 + (uint)bVar1 * 6 + 6);
    uStack_1a = *(ushort *)(pcVar3 + (uint)bVar1 * 6 + 8);
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
  cStack_16 = *pcVar3;
  cStack_15 = pcVar3[1];
  uStack_22 = (undefined1)uStack_14;
  uStack_14 = CONCAT22(*(undefined2 *)(puVar4 + 10),(undefined2)uStack_14);
  uStack_14 = CONCAT31(uStack_14._1_3_,*(undefined1 *)(_p_llm_env + 0xc6));
  if (cStack_16 != '\x01') {
    if ((cStack_16 == '\0') || (cStack_16 == '\x02')) {
      uStack_28 = *(undefined4 *)(_p_llm_env + 0xc);
      uStack_24 = *(undefined2 *)(_p_llm_env + 0x10);
      goto _L380;
    }
    if (cStack_16 != '\x03') {
      r_assert_param(0,"llm_scan.c",0x8e5);
      goto _L380;
    }
  }
  memcpy(&uStack_28,(void *)(_p_llm_env + 0x12),6);
_L380:
  iVar2 = r_lld_scan_start_eco(param_1,&uStack_28);
  if (iVar2 != 0) {
    r_assert_err(0,"llm_scan.c",0x8ed);
  }
  return;
}

