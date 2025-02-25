/*
 * Last changed at upstream commit 2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * https://github.com/espressif/esp32c3-bt-lib/commit/2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * Upstream date: 2025-02-25 15:16:47 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(723439d)
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
  undefined1 *puVar4;
  undefined2 uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int *piVar9;
  uint uVar10;
  uint uVar11;
  int *piVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  code *pcVar18;
  int aiStack_44 [4];
  
  piVar12 = param_1 + 1;
  iVar14 = 0;
  iVar3 = -1;
  puVar4 = (undefined1 *)((int)param_1 + 0x2e);
  do {
    piVar9 = *(int **)(*(int *)(_ble_log_async_env + 0xc) + iVar14);
    if ((*(byte *)(piVar9 + 6) & 1) == 0) {
_L17:
      *puVar4 = 0;
    }
    else {
      iVar13 = piVar9[1];
      piVar12[3] = iVar13;
      iVar15 = *piVar9;
      *piVar12 = iVar15;
      if (iVar13 == iVar15) goto _L17;
      *puVar4 = 1;
      if (iVar3 == -1) {
        iVar3 = ((int)puVar4 - ((int)param_1 + 0x2e)) * 0x1000000 >> 0x18;
      }
      iVar16 = piVar9[2];
      iVar15 = ble_log_async_timestamp_get(piVar9[5],iVar16);
      iVar13 = _ble_log_async_env;
      piVar12[6] = iVar15;
      uVar5 = ble_log_async_length_get
                        (*(undefined4 *)(*(int *)(*(int *)(iVar13 + 0xc) + iVar14) + 0x14),
                         piVar12[3],iVar16);
      *(undefined2 *)(((int)puVar4 * 2 - (int)param_1) + -0x34) = uVar5;
    }
    iVar14 = iVar14 + 4;
    puVar4 = puVar4 + 1;
    piVar12 = piVar12 + 1;
    if (iVar14 == 0xc) {
      do {
        if (iVar3 == -1) {
          return;
        }
        uVar8 = param_1[iVar3 + 7];
        for (uVar10 = iVar3 + 1U & 0xff; (uVar10 & 0xff) < 3; uVar10 = uVar10 + 1) {
          if ((*(char *)((int)param_1 + uVar10 + 0x2e) != '\0') &&
             ((uint)param_1[uVar10 + 7] < uVar8)) {
            iVar3 = (int)(char)uVar10;
            uVar8 = param_1[uVar10 + 7];
          }
        }
        iVar15 = iVar3 * 4;
        uVar10 = param_1[iVar3 + 4];
        iVar13 = *(int *)(*(int *)(_ble_log_async_env + 0xc) + iVar15);
        uVar17 = *(uint *)(iVar13 + 8);
        pcVar18 = *(code **)(*param_1 + 4);
        iVar14 = *(int *)(iVar13 + 0x14);
        uVar11 = (uint)*(ushort *)((int)param_1 + iVar3 * 2 + 0x28);
        uVar6 = ble_log_async_length_get(iVar14,uVar10,uVar17);
        aiStack_44[0] = 0;
        uVar8 = uVar10;
        for (uVar7 = 0; uVar6 != uVar7; uVar7 = uVar7 + 1 & 0xffff) {
          aiStack_44[0] = aiStack_44[0] + (uint)*(byte *)(iVar14 + uVar8);
          uVar1 = uVar8 + 1;
          if (uVar17 <= uVar1) {
            uVar1 = (1 - uVar17) + uVar8;
          }
          uVar8 = uVar1;
        }
        iVar14 = iVar14 + uVar10;
        uVar8 = uVar10 + uVar11;
        if (uVar17 - uVar10 < uVar11) {
          (*pcVar18)(uVar17 - uVar10,iVar14,0);
          iVar14 = *(int *)(iVar13 + 0x14);
          uVar11 = uVar8 - uVar17;
        }
        (*pcVar18)(uVar11,iVar14,0);
        (*pcVar18)(4,aiStack_44,1);
        if (uVar8 < *(uint *)(iVar13 + 8)) {
          *(uint *)(iVar13 + 4) = uVar8;
        }
        else {
          *(uint *)(iVar13 + 4) = uVar8 - *(uint *)(iVar13 + 8);
        }
        iVar14 = *(int *)(*(int *)(_ble_log_async_env + 0xc) + iVar15);
        uVar10 = *(uint *)(iVar14 + 8);
        if (uVar10 <= uVar8) {
          uVar8 = uVar8 - uVar10;
        }
        param_1[iVar3 + 4] = uVar8;
        if (param_1[iVar3 + 4] == param_1[iVar3 + 1]) {
          *(undefined1 *)((int)param_1 + iVar3 + 0x2e) = 0;
        }
        else {
          iVar13 = ble_log_async_timestamp_get(*(undefined4 *)(iVar14 + 0x14),uVar10);
          iVar14 = _ble_log_async_env;
          param_1[iVar3 + 7] = iVar13;
          uVar5 = ble_log_async_length_get
                            (*(undefined4 *)(*(int *)(iVar15 + *(int *)(iVar14 + 0xc)) + 0x14),
                             param_1[iVar3 + 4],uVar10);
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

