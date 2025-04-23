/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> ble_log_async_output.o -> ble_log_async_flush
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ble_log_async_flush(int *param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined2 uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int *piVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  undefined1 *puVar15;
  int *piVar16;
  int iVar17;
  int *piVar18;
  code *pcVar19;
  int iVar20;
  uint uVar21;
  int aiStack_44 [4];
  
  iVar2 = -1;
  piVar16 = param_1 + 1;
  piVar18 = param_1 + 10;
  puVar15 = (undefined1 *)((int)param_1 + 0x2e);
  iVar4 = 0;
  do {
    piVar11 = *(int **)(*(int *)(_ble_log_async_env + 0xc) + iVar4 * 4);
    if ((*(byte *)(piVar11 + 6) & 1) == 0) {
_L19:
      *puVar15 = 0;
    }
    else {
      iVar17 = piVar11[1];
      piVar16[3] = iVar17;
      iVar10 = *piVar11;
      *piVar16 = iVar10;
      if (iVar17 == iVar10) goto _L19;
      *puVar15 = 1;
      if (iVar2 == -1) {
        iVar2 = (int)(char)iVar4;
      }
      iVar20 = piVar11[5];
      iVar8 = piVar11[2];
      iVar10 = ble_log_async_timestamp_get(iVar20);
      piVar16[6] = iVar10;
      uVar5 = ble_log_async_length_get(iVar20,iVar17,iVar8);
      *(undefined2 *)piVar18 = uVar5;
    }
    iVar4 = iVar4 + 1;
    piVar16 = piVar16 + 1;
    piVar18 = (int *)((int)piVar18 + 2);
    puVar15 = puVar15 + 1;
    if (iVar4 == 3) {
      if (iVar2 == -1) {
        return;
      }
      do {
        uVar9 = param_1[iVar2 + 7];
        for (uVar12 = iVar2 + 1U & 0xff; (uVar12 & 0xff) != 3; uVar12 = uVar12 + 1) {
          if ((*(char *)((int)param_1 + uVar12 + 0x2e) != '\0') &&
             ((uint)param_1[uVar12 + 7] < uVar9)) {
            iVar2 = (int)(char)uVar12;
            uVar9 = param_1[uVar12 + 7];
          }
        }
        uVar12 = param_1[iVar2 + 4];
        iVar17 = *(int *)(*(int *)(_ble_log_async_env + 0xc) + iVar2 * 4);
        uVar21 = *(uint *)(iVar17 + 8);
        iVar4 = *(int *)(iVar17 + 0x14);
        uVar14 = (uint)*(ushort *)((int)param_1 + iVar2 * 2 + 0x28);
        pcVar19 = *(code **)(*param_1 + 4);
        uVar6 = ble_log_async_length_get(iVar4,uVar12,uVar21);
        aiStack_44[0] = 0;
        uVar9 = uVar12;
        for (uVar13 = 0; uVar6 != uVar13; uVar13 = uVar13 + 1 & 0xffff) {
          aiStack_44[0] = aiStack_44[0] + (uint)*(byte *)(iVar4 + uVar9);
          uVar7 = uVar9 + 1;
          if (uVar21 <= uVar7) {
            uVar7 = (1 - uVar21) + uVar9;
          }
          uVar9 = uVar7;
        }
        iVar4 = iVar4 + uVar12;
        uVar9 = uVar12 + uVar14;
        if (uVar21 - uVar12 < uVar14) {
          (*pcVar19)(uVar21 - uVar12,iVar4,0);
          iVar4 = *(int *)(iVar17 + 0x14);
          uVar14 = uVar9 - uVar21;
        }
        (*pcVar19)(uVar14,iVar4,0);
        (*pcVar19)(4,aiStack_44,1);
        uVar12 = uVar9;
        if (*(uint *)(iVar17 + 8) <= uVar9) {
          uVar12 = uVar9 - *(uint *)(iVar17 + 8);
        }
        *(uint *)(iVar17 + 4) = uVar12;
        iVar4 = *(int *)(*(int *)(_ble_log_async_env + 0xc) + iVar2 * 4);
        uVar12 = *(uint *)(iVar4 + 8);
        if (uVar12 <= uVar9) {
          uVar9 = uVar9 - uVar12;
        }
        param_1[iVar2 + 4] = uVar9;
        if (uVar9 == param_1[iVar2 + 1]) {
          *(undefined1 *)((int)param_1 + iVar2 + 0x2e) = 0;
        }
        else {
          uVar3 = *(undefined4 *)(iVar4 + 0x14);
          iVar4 = ble_log_async_timestamp_get(uVar3,uVar9);
          param_1[iVar2 + 7] = iVar4;
          uVar5 = ble_log_async_length_get(uVar3,uVar9,uVar12);
          *(undefined2 *)((int)param_1 + iVar2 * 2 + 0x28) = uVar5;
        }
        if (*(char *)((int)param_1 + 0x2e) == '\0') {
          if (*(char *)((int)param_1 + 0x2f) == '\0') {
            if ((char)param_1[0xc] == '\0') {
              return;
            }
            cVar1 = '\x02';
          }
          else {
            cVar1 = '\x01';
          }
        }
        else {
          cVar1 = '\0';
        }
        iVar2 = (int)cVar1;
      } while( true );
    }
  } while( true );
}

