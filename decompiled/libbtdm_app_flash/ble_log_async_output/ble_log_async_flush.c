/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> ble_log_async_output.o -> ble_log_async_flush
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ble_log_async_flush(int *param_1)

{
  uint uVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  undefined2 uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  int *piVar12;
  uint uVar13;
  int iVar14;
  int *piVar15;
  int iVar16;
  undefined1 *puVar17;
  int *piVar18;
  code *pcVar19;
  int iVar20;
  uint uVar21;
  int aiStack_44 [4];
  
  puVar17 = (undefined1 *)((int)param_1 + 0x2e);
  piVar15 = param_1 + 1;
  piVar18 = param_1 + 10;
  iVar14 = 0;
  iVar3 = -1;
  do {
    piVar12 = *(int **)(*(int *)(_ble_log_async_env + 0xc) + iVar14 * 4);
    if ((*(byte *)(piVar12 + 6) & 1) == 0) {
_L17:
      *puVar17 = 0;
    }
    else {
      iVar16 = piVar12[1];
      piVar15[3] = iVar16;
      iVar10 = *piVar12;
      *piVar15 = iVar10;
      if (iVar16 == iVar10) goto _L17;
      *puVar17 = 1;
      if (iVar3 == -1) {
        iVar3 = (int)(char)iVar14;
      }
      iVar20 = piVar12[5];
      iVar8 = piVar12[2];
      iVar10 = ble_log_async_timestamp_get(iVar20);
      piVar15[6] = iVar10;
      uVar5 = ble_log_async_length_get(iVar20,iVar16,iVar8);
      *(undefined2 *)piVar18 = uVar5;
    }
    iVar14 = iVar14 + 1;
    puVar17 = puVar17 + 1;
    piVar15 = piVar15 + 1;
    piVar18 = (int *)((int)piVar18 + 2);
    if (iVar14 == 3) {
      do {
        if (iVar3 == -1) {
          return;
        }
        uVar9 = param_1[iVar3 + 7];
        for (uVar13 = iVar3 + 1U & 0xff; (uVar13 & 0xff) < 3; uVar13 = uVar13 + 1) {
          if ((*(char *)((int)param_1 + uVar13 + 0x2e) != '\0') &&
             ((uint)param_1[uVar13 + 7] < uVar9)) {
            iVar3 = (int)(char)uVar13;
            uVar9 = param_1[uVar13 + 7];
          }
        }
        uVar7 = param_1[iVar3 + 4];
        iVar16 = *(int *)(*(int *)(_ble_log_async_env + 0xc) + iVar3 * 4);
        uVar21 = *(uint *)(iVar16 + 8);
        pcVar19 = *(code **)(*param_1 + 4);
        iVar14 = *(int *)(iVar16 + 0x14);
        uVar13 = (uint)*(ushort *)((int)param_1 + iVar3 * 2 + 0x28);
        uVar6 = ble_log_async_length_get(iVar14,uVar21);
        aiStack_44[0] = 0;
        uVar9 = uVar7;
        for (uVar11 = 0; uVar6 != uVar11; uVar11 = uVar11 + 1 & 0xffff) {
          aiStack_44[0] = aiStack_44[0] + (uint)*(byte *)(iVar14 + uVar9);
          uVar1 = uVar9 + 1;
          if (uVar21 <= uVar9 + 1) {
            uVar1 = (1 - uVar21) + uVar9;
          }
          uVar9 = uVar1;
        }
        uVar9 = uVar7 + uVar13;
        iVar14 = uVar7 + iVar14;
        if (uVar21 - uVar7 < uVar13) {
          (*pcVar19)(uVar21 - uVar7,iVar14,0,0,1);
          iVar14 = *(int *)(iVar16 + 0x14);
          uVar13 = uVar9 - uVar21;
        }
        (*pcVar19)(uVar13,iVar14,4,aiStack_44,2);
        uVar13 = uVar9;
        if (*(uint *)(iVar16 + 8) <= uVar9) {
          uVar13 = uVar9 - *(uint *)(iVar16 + 8);
        }
        *(uint *)(iVar16 + 4) = uVar13;
        iVar14 = *(int *)(*(int *)(_ble_log_async_env + 0xc) + iVar3 * 4);
        uVar13 = *(uint *)(iVar14 + 8);
        if (uVar13 <= uVar9) {
          uVar9 = uVar9 - uVar13;
        }
        param_1[iVar3 + 4] = uVar9;
        if (param_1[iVar3 + 1] == uVar9) {
          *(undefined1 *)((int)param_1 + iVar3 + 0x2e) = 0;
        }
        else {
          uVar4 = *(undefined4 *)(iVar14 + 0x14);
          iVar14 = ble_log_async_timestamp_get(uVar4,uVar9);
          param_1[iVar3 + 7] = iVar14;
          uVar5 = ble_log_async_length_get(uVar4,uVar9,uVar13);
          *(undefined2 *)((int)param_1 + iVar3 * 2 + 0x28) = uVar5;
        }
        if (*(char *)((int)param_1 + 0x2e) == '\0') {
          if (*(char *)((int)param_1 + 0x2f) == '\0') {
            if ((char)param_1[0xc] == '\0') {
              return;
            }
            cVar2 = '\x02';
          }
          else {
            cVar2 = '\x01';
          }
        }
        else {
          cVar2 = '\0';
        }
        iVar3 = (int)cVar2;
      } while( true );
    }
  } while( true );
}

