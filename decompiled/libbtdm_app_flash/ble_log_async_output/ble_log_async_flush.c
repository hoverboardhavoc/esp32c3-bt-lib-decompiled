/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
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
  uint uVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  undefined2 uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int *piVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  int *piVar16;
  code *pcVar17;
  undefined1 *puVar18;
  int *piVar19;
  int iVar20;
  uint uVar21;
  int aiStack_44 [4];
  
  puVar18 = (undefined1 *)((int)param_1 + 0x2e);
  piVar16 = param_1 + 1;
  piVar19 = param_1 + 10;
  iVar14 = 0;
  iVar3 = -1;
  do {
    piVar10 = *(int **)(*(int *)(_ble_log_async_env + 0xc) + iVar14 * 4);
    if ((*(byte *)(piVar10 + 6) & 1) == 0) {
_L17:
      *puVar18 = 0;
    }
    else {
      iVar15 = piVar10[1];
      piVar16[3] = iVar15;
      iVar9 = *piVar10;
      *piVar16 = iVar9;
      if (iVar15 == iVar9) goto _L17;
      *puVar18 = 1;
      if (iVar3 == -1) {
        iVar3 = (int)(char)iVar14;
      }
      iVar20 = piVar10[5];
      iVar7 = piVar10[2];
      iVar9 = ble_log_async_timestamp_get(iVar20);
      piVar16[6] = iVar9;
      uVar5 = ble_log_async_length_get(iVar20,iVar15,iVar7);
      *(undefined2 *)piVar19 = uVar5;
    }
    iVar14 = iVar14 + 1;
    puVar18 = puVar18 + 1;
    piVar16 = piVar16 + 1;
    piVar19 = (int *)((int)piVar19 + 2);
    if (iVar14 == 3) {
      do {
        if (iVar3 == -1) {
          return;
        }
        uVar8 = param_1[iVar3 + 7];
        for (uVar11 = iVar3 + 1U & 0xff; (uVar11 & 0xff) < 3; uVar11 = uVar11 + 1) {
          if ((*(char *)((int)param_1 + uVar11 + 0x2e) != '\0') &&
             ((uint)param_1[uVar11 + 7] < uVar8)) {
            iVar3 = (int)(char)uVar11;
            uVar8 = param_1[uVar11 + 7];
          }
        }
        uVar6 = param_1[iVar3 + 4];
        iVar15 = *(int *)(*(int *)(_ble_log_async_env + 0xc) + iVar3 * 4);
        iVar14 = *(int *)(iVar15 + 0x14);
        uVar21 = *(uint *)(iVar15 + 8);
        uVar13 = (uint)*(ushort *)((int)param_1 + iVar3 * 2 + 0x28);
        pcVar17 = *(code **)(*param_1 + 4);
        uVar11 = ble_log_async_length_get(iVar14,uVar21);
        aiStack_44[0] = 0;
        uVar8 = uVar6;
        for (uVar12 = 0; uVar11 != uVar12; uVar12 = uVar12 + 1 & 0xffff) {
          aiStack_44[0] = aiStack_44[0] + (uint)*(byte *)(iVar14 + uVar8);
          uVar1 = uVar8 + 1;
          if (uVar21 <= uVar8 + 1) {
            uVar1 = (1 - uVar21) + uVar8;
          }
          uVar8 = uVar1;
        }
        uVar8 = uVar6 + uVar13;
        iVar14 = uVar6 + iVar14;
        if (uVar21 - uVar6 < uVar13) {
          (*pcVar17)(uVar21 - uVar6,iVar14,0);
          iVar14 = *(int *)(iVar15 + 0x14);
          uVar13 = uVar8 - uVar21;
        }
        (*pcVar17)(uVar13,iVar14,0);
        (*pcVar17)(4,aiStack_44,1);
        uVar11 = uVar8;
        if (*(uint *)(iVar15 + 8) <= uVar8) {
          uVar11 = uVar8 - *(uint *)(iVar15 + 8);
        }
        *(uint *)(iVar15 + 4) = uVar11;
        iVar14 = *(int *)(*(int *)(_ble_log_async_env + 0xc) + iVar3 * 4);
        uVar11 = *(uint *)(iVar14 + 8);
        if (uVar11 <= uVar8) {
          uVar8 = uVar8 - uVar11;
        }
        param_1[iVar3 + 4] = uVar8;
        if (param_1[iVar3 + 1] == uVar8) {
          *(undefined1 *)((int)param_1 + iVar3 + 0x2e) = 0;
        }
        else {
          uVar4 = *(undefined4 *)(iVar14 + 0x14);
          iVar14 = ble_log_async_timestamp_get(uVar4,uVar8);
          param_1[iVar3 + 7] = iVar14;
          uVar5 = ble_log_async_length_get(uVar4,uVar8,uVar11);
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

